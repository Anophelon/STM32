#include "stm32f4xx.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void RCC_Init(void);
void GPIO_Init(void);
void UART_Init(void);

void LedErOn (void);
void USART1_send (char chr);
void USART1_send_string (char *str);

void vTaskLed1 (void *argument);
void vTaskBut2 (void *argument);

int main(void){
	RCC_Init();
	GPIO_Init();
	UART_Init();

	xTaskCreate(vTaskLed1,"LED1",32,NULL,1,NULL);
	xTaskCreate(vTaskBut2,"BUT",32,NULL,1,NULL);

	vTaskStartScheduler();								//planner

	while(1)LedErOn();
}

//**********************************************************************************

void vTaskLed1 (void *argument){
	while(1){
		GPIOD->ODR |= GPIO_ODR_ODR_12;			//turn on led blue
		GPIOD->ODR &= ~GPIO_ODR_ODR_13;			//turn off led orange
		//USART1_send('1');

		vTaskDelay(10000);
		GPIOD->ODR |= GPIO_ODR_ODR_13;			//turn on led orange
		GPIOD->ODR &= ~GPIO_ODR_ODR_12;			//turn off led blue
		//USART1_send('0');

		vTaskDelay(10000);
	}
}

void vTaskBut2 (void *argument){
	while(1){
			USART1_send_string("Button\r\n");
					USART1_send(6);
					vTaskDelay(5000);
	}
}
//**********************************************************************************


void RCC_Init(void){
	RCC->CR |= ((uint32_t)RCC_CR_HSEON); 												// Enable HSE
	while (!(RCC->CR & RCC_CR_HSERDY));													// Ready start HSE

	FLASH->ACR = (FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY|
							 FLASH_ACR_ICEN | FLASH_ACR_DCEN);							// Cloclk Flash memory

	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;														// AHB = SYSCLK/1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;														// APB1 = HCLK/4
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;														// APB2 = HCLK/2

	RCC->CFGR &= ~RCC_PLLCFGR_PLLSRC;														// clearn PLLSRC bits
	RCC->CFGR &= ~RCC_PLLCFGR_PLLM;               							// clearn PLLM bits
	RCC->CFGR &= ~RCC_PLLCFGR_PLLN;															// clearn PLLN bits
	RCC->CFGR &= ~RCC_PLLCFGR_PLLP;															// clearn PLLP bits

	RCC->CFGR |= RCC_PLLCFGR_PLLSRC_HSE; 												// source HSE = 8MHz
	RCC->CFGR |= RCC_PLLCFGR_PLLM_4; 														// source HSE/4 = 2 MHz
	RCC->CFGR |= (RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLN_5
																	 | RCC_PLLCFGR_PLLN_3); 		// is set N mul: PLLM x168: clock = 2 MHz * 168 = 336 MHz
	// already RCC_PLLCFGR_PLLP = 0; 														// PLLN/2 = 336 MHz * 2 = 168 MHz

	RCC->CR |= RCC_CR_PLLON;                      							// enable PLL
	while((RCC->CR & RCC_CR_PLLRDY) == 0) {}      							// wait till PLL is ready

	RCC->CFGR &= ~RCC_CFGR_SW;                   							 	// clear SW bits
  RCC->CFGR |= RCC_CFGR_SW_PLL;                 							// select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {} 			// wait till PLL is used
}

void GPIO_Init (void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	//Turn on clock on AHB1 to GPIOD
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	//Turn on clock on AHB1 to GPIOA

	GPIOD->MODER &= ~GPIO_MODER_MODER15;	//PD15 - clear - led blue
	GPIOD->MODER |= GPIO_MODER_MODER15_0;	//PD15 - PP - led blue

	GPIOD->MODER &= ~GPIO_MODER_MODER14;	//PD14 - clear - led red
	GPIOD->MODER |= GPIO_MODER_MODER14_0;	//PD14 - PP - led red

	GPIOD->MODER &= ~GPIO_MODER_MODER13;	//PD15 - clear - led orange
	GPIOD->MODER |= GPIO_MODER_MODER13_0;	//PD13 - PP - led orange

	GPIOD->MODER &= ~GPIO_MODER_MODER12;	//PD15 - clear - led green
	GPIOD->MODER |= GPIO_MODER_MODER12_0;	//PD12 - PP - led green

	GPIOD->OSPEEDR = 0;					//low speed for all gpiod
	GPIOD->OTYPER = 0;

	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR0;		//PA0 - crear & pin is floating - Button USER
	//GPIOA->PUPDR |= GPIO_PUPDR_PUPDR0_0;	//PA0 - PU - Button USER
}

void UART_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;				//Turn on clock on APB2 to UASRT1
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;				//Turn on clock on AHB1 to GPIOA

	//PA9 - TX
	GPIOA->MODER &= ~GPIO_MODER_MODER9_0;				//MODER 10
	GPIOA->MODER |= GPIO_MODER_MODER9_1;				//MODER 10
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR9;					//PUPDR 00
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_9;					//OTYPER 0 => PA9 - AF PP
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;		//OSPEED 11 - very high speed

	//PA10 - RX
	GPIOA->MODER &= ~GPIO_MODER_MODER10;				//MODER 00
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR10;				//PUPDR 0 => PA10 - floating input
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;	//OSPEED 11 - very high speed

	USART1->BRR = 0x0000222E;										// (f(APB2) - 9600/2)/9600, f(APB2) == 82 MHz
	USART1->CR1 |= USART_CR1_UE;								//Enable USART1
	USART1->CR1 |= USART_CR1_TE;								//Transmitter USART1
	USART1->CR1 |= USART_CR1_RE;								//Resiver USART1

	USART1->CR1 |= USART_CR1_RXNEIE;						//RX Interrupt Enable
	NVIC_EnableIRQ(USART1_IRQn);
}

void USART1_send_string(char *str){
	int i = 0;
	while(str[i])
		USART1_send(str[i++]);
}
void USART1_IRQHandler(void){
	if (USART1->SR & USART_SR_RXNE){
		USART1->SR &= ~USART_SR_RXNE;
		if(USART1->DR == '0'){
		//	USART1_send_string("OFF\r\n");
		//	USART1_send('0');
			GPIOD->ODR &= ~GPIO_ODR_ODR_15;			//turn on led blue
		}
		if(USART1->DR == '1'){
		//	USART1_send_string("ON\r\n");
	//		USART1_send('1');
			GPIOD->ODR |= GPIO_ODR_ODR_15;			//turn on led blue
		}
	}
}

void LedErOn (void){
	GPIOD->ODR = GPIO_ODR_ODR_14;					//turn on led red
}
