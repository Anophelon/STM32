/************************************* Library **********************************************/
#include "stm32f4xx.h"                  // Device header

/************************************* Defines **********************************************/

//---Переопределяем порты для подключения дисплея, для удобства---//
#define     LCM_OUT               GPIOB->ODR
#define     LCM_PIN_RS            GPIO_ODR_ODR_0          // PB0
#define     LCM_PIN_EN            GPIO_ODR_ODR_1          // PB1
#define     LCM_PIN_D7            GPIO_ODR_ODR_7          // PB7
#define     LCM_PIN_D6            GPIO_ODR_ODR_6          // PB6
#define     LCM_PIN_D5            GPIO_ODR_ODR_5          // PB5
#define     LCM_PIN_D4            GPIO_ODR_ODR_4          // PB4
#define     LCM_PIN_MASK  ((LCM_PIN_RS | LCM_PIN_EN | LCM_PIN_D7 | LCM_PIN_D6 | LCM_PIN_D5 | LCM_PIN_D4))
/********************************** Use Functions *******************************************/

	void delay(int a);
	void PulseLCD(void);
	void SendByte(char ByteToSend, int IsData);
	void Cursor(char Row, char Col);
	void ClearLCDScreen(void);
	void InitializeLCD(void);
	void PrintStr(char *Text);

