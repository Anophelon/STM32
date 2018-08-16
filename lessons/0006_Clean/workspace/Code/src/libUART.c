/************************************* Library **********************************************/
#include "libUART.h"

/********************************** Use Functions *******************************************/

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
void SendDataUSART2 (uint8_t data){
	while (!(USART2->SR & USART_SR_TC));
	USART2->DR = data;
}
