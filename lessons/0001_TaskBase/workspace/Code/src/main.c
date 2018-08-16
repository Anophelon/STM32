#include "stm32f4xx.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


void LedErGPIO_init(void);
void GPIO_Init(void);
void LedErOn (void);
void vTaskLed1 (void *argument);
void vTaskLed2 (void *argument);

int main(void)
{
	GPIO_Init();
	LedErGPIO_init();
	
	xTaskCreate(vTaskLed1,"LED1",32,NULL,1,NULL);
	xTaskCreate(vTaskLed2,"LED2",32,NULL,1,NULL);

	vTaskStartScheduler();//planner
	
	while(1)
	{
		LedErOn();
	}
}

//**********************************************************************************

void GPIO_Init (void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	//Turn on clock on AHB1 to GPIOD
	GPIOD->MODER |= 0x55000000;
	GPIOD->OSPEEDR |= 0x00000000;
	GPIOD->OTYPER &= 0;
}

void vTaskLed1 (void *argument){
	while(1){
		GPIOD->ODR |= 0x8000;
		vTaskDelay(5000);//1 mc
		GPIOD->ODR &= ~0x8000;
		vTaskDelay(5000);//1 mc
	}
}

void vTaskLed2 (void *argument){
	while(1){
		GPIOD->ODR &= ~0x2000;
		vTaskDelay(5000);//1 mc
		GPIOD->ODR |= 0x2000;
		vTaskDelay(5000);
	}
}

void LedErGPIO_init(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	//Turn on clock on AHB1 to GPIOD
	GPIOD->MODER |= 0x10000000;
	GPIOD->OSPEEDR |= 0x00000000;
	GPIOD->OTYPER &= 0;
}
void LedErOn (void){
	GPIOD->ODR = 0x4000;
}
