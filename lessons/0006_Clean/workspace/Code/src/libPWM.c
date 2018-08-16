/************************************* Library **********************************************/
#include "libPWM.h"

/********************************** Use Functions *******************************************/
void InitTIM2(void){//PA1 ch2
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//clock AHB1 for PA1
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;//clock APB1 for TIM2

	GPIOA->MODER 		|= GPIO_MODER_MODER1_0;//MODER 01 - PP
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
