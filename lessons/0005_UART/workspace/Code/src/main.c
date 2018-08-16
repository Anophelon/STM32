#include "stm32f4xx.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void InitRCC(void);
//void MCO_out(void);
void InitGPIO(void);
void InitUART(void);
void InitTIM2(void);

void LedErOn (void);
void SendUSART2 (char chr);
void SendStringUSART2 (char *str);

void vTaskLed1 (void *argument);
void vTaskBut2 (void *argument);


int main(void){
	InitRCC();
	//MCO_out();
	InitGPIO();
	InitUART();
	InitTIM2();


	xTaskCreate(vTaskLed1,"LED1",32,NULL,1,NULL);
	xTaskCreate(vTaskBut2,"BUT",32,NULL,1,NULL);

	vTaskStartScheduler();								//planner

	while(1)LedErOn();
}

//**********************************************************************************

void vTaskLed1 (void *argument){
	while(1){
		GPIOD->ODR |= GPIO_ODR_ODR_12;			//turn on led green
		GPIOD->ODR &= ~GPIO_ODR_ODR_13;			//turn off led orange
		vTaskDelay(1000);
		GPIOD->ODR |= GPIO_ODR_ODR_13;			//turn on led orange
		GPIOD->ODR &= ~GPIO_ODR_ODR_12;			//turn off led green
		vTaskDelay(1000);
	}
}

void vTaskBut2 (void *argument){
	while(1){
		while((GPIOA->IDR & GPIO_IDR_IDR_0) != 0){
			vTaskDelay(100);
			SendStringUSART2("Button\r\n");
		}
		vTaskDelay(100);
	}
}
//**********************************************************************************

void InitRCC(void){
	RCC->CR |= ((uint32_t)RCC_CR_HSEON); 												// Enable HSE
	while (!(RCC->CR & RCC_CR_HSERDY));													// Ready start HSE

	FLASH->ACR |= FLASH_ACR_PRFTEN 	|
								FLASH_ACR_LATENCY |
							 	FLASH_ACR_ICEN 		|
								FLASH_ACR_DCEN;																// Cloclk Flash memory

	RCC->CFGR |= RCC_CFGR_HPRE_DIV1	 |													// AHB = SYSCLK/1 = 168/1
				 			 RCC_CFGR_PPRE1_DIV4 |													// APB1 = HCLK/4 = 168/4 = 42
							 RCC_CFGR_PPRE2_DIV2;														// APB2 = HCLK/2 = 84

	RCC->CFGR |= RCC_PLLCFGR_PLLSRC_HSE | 											// source HSE = 8MHz
	 						 RCC_PLLCFGR_PLLM_3 		| 											// DIV_M: source HSE/8 = 1 MHz
							 RCC_PLLCFGR_PLLN_8 		| 											// is set N mul: PLLM x336:
							 RCC_PLLCFGR_PLLN_6		  |												// clock = 1 MHz * 336 = 336 MHz
							 RCC_PLLCFGR_PLLN_4	;
		// already RCC_PLLCFGR_PLLP = 0; PLLN/2 = 336 MHz * 2 = 168 MHz

	RCC->CR |= RCC_CR_PLLON;                      							// enable PLL
	while((RCC->CR & RCC_CR_PLLRDY) == 0) {}      							// wait till PLL is ready

  RCC->CFGR |= RCC_CFGR_SW_PLL;                 							// select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {} 			// wait till PLL is used
}

/*void MCO_out(void){ //PA8
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;				//Turn on clock on AHB1 to GPIOA

	GPIOA->MODER &= ~GPIO_MODER_MODER8_1;				//MODER 01
	GPIOA->MODER |= GPIO_MODER_MODER8_0;				//MODER 01

	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;		//OSPEED 11 - very high speed
}*/

void InitGPIO (void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN |		//Turn on clock on AHB1 to GPIOD
	 								RCC_AHB1ENR_GPIOAEN;		//Turn on clock on AHB1 to GPIOA

	GPIOD->MODER |= GPIO_MODER_MODER15_0 |	//PD15 - PP - led blue
 							 		GPIO_MODER_MODER14_0 |	//PD14 - PP - led red
									GPIO_MODER_MODER13_0 |	//PD13 - PP - led orange
		 							GPIO_MODER_MODER12_0;		//PD12 - PP - led green
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR0;		//PA0 - crear & pin is floating - Button USER
	//GPIOA->PUPDR |= GPIO_PUPDR_PUPDR0_0;	//PA0 - PU - Button USER
}

void InitUART(void){
	RCC->APB1ENR 		|= RCC_APB1ENR_USART2EN | 													//Turn on clock on APB1 to UASRT2
										 RCC_AHB1ENR_GPIOAEN;															//Turn on clock on AHB1 to GPIOA
	//PA2 - TX, PA3 - RX: PU AF
	GPIOA->MODER 		|= GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1;				//MODER 10
	GPIOA->OSPEEDR 	|= GPIO_OSPEEDER_OSPEEDR2 | GPIO_OSPEEDER_OSPEEDR3;	//OSPEED 11 - very high speed
	GPIOA->PUPDR 		|= GPIO_PUPDR_PUPDR2_0 | GPIO_PUPDR_PUPDR3_0;       //PUPDR 01
	GPIOA->AFR[0] 	|= 0x00007700;																			//PA2,PA3 - AF7

	//USART1->BRR =(APB1CLK+BAUDRATE/2)/BAUDRATE;
	USART2->BRR 		= 0x1117;											// (f(APB1)+ 4800)/9600, f(APB1) == 42 MHz
	USART2->CR1 	 |= USART_CR1_UE | 							//Enable USART2
								 		USART_CR1_TE | 							//Transmitter USART2
								 		USART_CR1_RE |							//Resiver USART2
								 		USART_CR1_RXNEIE;						//RX Interrupt Enable
	//USART2->CR2 = 0;
	//USART2->CR3 = 0;
	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_SetPriority(USART2_IRQn,4);
}

void SendUSART2 (char chr){
	while(!(USART2->SR & USART_SR_TC));
	USART2->DR = chr;
}

void SendStringUSART2(char *str){
	uint8_t i = 0;
	while(str[i]){
			SendUSART2(str[i++]);
		}
}

void USART2_IRQHandler(void){
	if ((USART2->SR & USART_SR_RXNE) != 0){	//check about data on RX
		USART2->SR &= ~USART_SR_RXNE;

		if(USART2->DR == '0'){
			SendUSART2('0');
			SendUSART2('\n');
			SendStringUSART2("OFF\r\n");
			GPIOD->ODR &= ~GPIO_ODR_ODR_15;			//turn off led blue
		}
		if(USART2->DR == '1'){
			SendUSART2('1');
			SendUSART2('\n');
			SendStringUSART2("ON\r\n");
			GPIOD->ODR |= GPIO_ODR_ODR_15;			//turn on led blue
		}
	}
}

void InitTIM2(void){//PA1 ch2
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//clock AHB1 for PA1
	RCC->APB1ENR |= RCC_APB1RCC_APB1ENR_TIM2EN;//clock APB1 for TIM2

	GRIOA->MODER 		|= GPIO_MODER_MODER1_0;//MODER 01 - PP
	GPIOA->OSPEEDR 	|= GPIO_OSPEEDER_OSPEEDR1;

	TIM2->PSC |= 42 - 1;
	TIM2->ARR = 1000;
	TIM2->CCR1 = 500;

	TIM2->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
	TIM2->CCER 	|= TIM_CCER_CC2E;
	TIM2->CCER 	&= ~TIM_CCER_CC2P;
	TIM2->CR1		&= ~TIM_CR1_DIR;
	TIM2->CR1		|= TIM_CR1_CEN;



}

void LedErOn (void){
	GPIOD->ODR = GPIO_ODR_ODR_14;					//turn on led red
}
