/************************************* Library **********************************************/
#include "stm32f4xx.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "initSys.h"
#include "libUART.h"
#include "libPWM.h"
#include "libLCD.h"
/************************************* Defines **********************************************/
xQueueHandle SendData;
void vTaskLed1 (void *argument);
void vTaskBut2 (void *argument);
void vTaskTest (void *argument);
