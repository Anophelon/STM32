#include "stm32f4xx.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void RCC_Init(void);
void GPIO_Init(void);
void LedErOn (void);
void vTaskLed1 (void *argument);
void vTaskBut2 (void *argument);

int main(void){
	RCC_Init();
	GPIO_Init();

//	xTaskCreate(vTaskLed1,"LED1",32,NULL,1,NULL);
	xTaskCreate(vTaskBut2,"BUT",32,NULL,1,NULL);

	vTaskStartScheduler();								//planner

	while(1)LedErOn();
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

void vTaskLed1 (void *argument){
	while(1){
		GPIOD->ODR |= GPIO_ODR_ODR_15;			//turn on led blue
		GPIOD->ODR &= ~GPIO_ODR_ODR_13;			//turn off led orange
		vTaskDelay(10000);
		GPIOD->ODR |= GPIO_ODR_ODR_13;			//turn on led orange
		GPIOD->ODR &= ~GPIO_ODR_ODR_15;			//turn off led blue
		vTaskDelay(10000);
	}
}

void vTaskBut2 (void *argument){
	while(1){
		if((GPIOA->IDR & GPIO_IDR_IDR_0) != 0){
			vTaskDelay(100);
			GPIOD->ODR ^= GPIO_ODR_ODR_15;			//turn on led blue
			GPIOD->ODR ^= GPIO_ODR_ODR_13;			//turn on led blue
		}
		vTaskDelay(200);
	}
}

void LedErOn (void){
	GPIOD->ODR = GPIO_ODR_ODR_14;					//turn on led red
}
