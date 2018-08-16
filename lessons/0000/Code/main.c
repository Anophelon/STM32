#include "stm32f4xx.h"                  // Device header

void delay(int time)
{
	for(int i = 0; i < time; i++)
	{
	}
}
int main(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	//Turn on clock on AHB1 to GPIOD
	GPIOD->MODER |= 0x55000000;
	GPIOD->OSPEEDR |= 0x00000000;
	GPIOD->OTYPER &= 0;
	GPIOD->ODR |= 0x0000;



	while(1)
	{

		GPIOD->ODR = 0x8000;
		delay(4000000);

		GPIOD->ODR = 0x2000;
		delay(4000000);

	}

}