#include "main.h"

int main(void){
	InitRCC();
	//genMCO();
	InitGPIO();
	InitUART();
	InitTIM2();

	xTaskCreate(vTaskLed1,"LED1",32,NULL,1,NULL);
	xTaskCreate(vTaskBut2,"BUT",32,NULL,1,NULL);
	xTaskCreate(vTaskTest,"Test",32,NULL,1,NULL);

	SendData = xQueueCreate( 5, sizeof( uint8_t ) );

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
		uint8_t i = 0;
		while((GPIOA->IDR & GPIO_IDR_IDR_0) != 0){
			vTaskDelay(100);
			SendStringUSART2("Button\r\n");
		}
		vTaskDelay(100);
		if(uxQueueMessagesWaiting(SendData) != 0){
			xQueueReceive(SendData, &i, 0);
		}
		SendDataUSART2(i);
		vTaskDelay(100);

	}
}

void vTaskTest (void *argument){
	uint8_t i = 30;
	while(1){
			xQueueSend(SendData, &i, 0);
			i++;
			vTaskDelay(200);
	}
}

//**********************************************************************************

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
