/************************************* Library **********************************************/
#include "initSys.h"

/********************************** Use Functions *******************************************/

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

/*void genMCO(void){ //PA8
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
void LedErOn (void){
	GPIOD->ODR = GPIO_ODR_ODR_14;					//turn on led red
}
