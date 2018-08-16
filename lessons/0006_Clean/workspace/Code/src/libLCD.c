/************************************* Library **********************************************/
#include "libLCD.h"                  // Device header

/********************************** Use Functions *******************************************/

//---Функция задержки---//
void delay(int a)
{
    int i = 0;
    int f = 0;
    while(f < a)
    {
        while(i<60)
            {i++;}
        f++;
    }
}

//---Нужная функция для работы с дисплеем, по сути "дергаем ножкой" EN---//
void PulseLCD(void)
{
    LCM_OUT &= ~LCM_PIN_EN;
    delay(220);
    LCM_OUT |= LCM_PIN_EN;
    delay(220);
    LCM_OUT &= (~LCM_PIN_EN);
    delay(220);
}

//---Отсылка байта в дисплей---//
void SendByte(char ByteToSend, int IsData)
{
    LCM_OUT &= (~LCM_PIN_MASK);
    LCM_OUT |= (ByteToSend & 0xF0);

    if (IsData == 1)
        LCM_OUT |= LCM_PIN_RS;
    else
        LCM_OUT &= ~LCM_PIN_RS;
    PulseLCD();
    LCM_OUT &= (~LCM_PIN_MASK);
    LCM_OUT |= ((ByteToSend & 0x0F) << 4);

    if (IsData == 1)
        LCM_OUT |= LCM_PIN_RS;
    else
        LCM_OUT &= ~LCM_PIN_RS;

    PulseLCD();
}

//---Установка позиции курсора---//
void Cursor(char Row, char Col)
{
   char address;
   if (Row == 0)
   address = 0;
   else
   address = 0x40;
   address |= Col;
   SendByte(0x80 | address, 0);
}

//---Очистка дисплея---//
void ClearLCDScreen(void)
{
    SendByte(0x01, 0);
    SendByte(0x02, 0);
}

//---Инициализация дисплея---//
void InitializeLCD(void)
{
    RCC->AHB1ENR    |= RCC_AHB1ENR_GPIOBEN;		//Turn on clock on AHB1 to GPIOB
    GPIOB->MODER    |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER4_0 |
                       GPIO_MODER_MODER5_0 | GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0;
    GPIOB->OSPEEDR  |= GPIO_OSPEEDER_OSPEEDR0 | GPIO_OSPEEDER_OSPEEDR1 | GPIO_OSPEEDER_OSPEEDR4 |
                       GPIO_OSPEEDER_OSPEEDR5 | GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7;
    LCM_OUT &= ~(LCM_PIN_MASK);
    delay(32000);
    delay(32000);
    delay(32000);
    LCM_OUT &= ~LCM_PIN_RS;
    LCM_OUT &= ~LCM_PIN_EN;
    LCM_OUT = 0x20;
    PulseLCD();
    SendByte(0x28, 0);
    SendByte(0x0E, 0);
    SendByte(0x06, 0);
}

//---Печать строки---//
void PrintStr(char *Text)
{
    char *c;
    c = Text;
    while ((c != 0) && (*c != 0))
    {
        SendByte(*c, 1);
        c++;
    }
}
