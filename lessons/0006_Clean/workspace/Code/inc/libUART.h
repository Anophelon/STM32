/************************************* Library **********************************************/
#include "stm32f4xx.h"                  // Device header

/********************************** Use Functions *******************************************/
void InitUART(void);
void SendUSART2 (char chr);
void SendStringUSART2 (char *str);
void SendDataUSART2 (uint8_t data);
