//**************************************************************************************************
// Filename							MT_WH1602.h				
// Platform     				STM32F10x/STM32F4xx
// Author								Aveal (http://microtechnics.ru/)
// Current version  		1.0.0    
// Date         				07.03.2013
//**************************************************************************************************

#ifndef MT_WH1602_H
#define MT_WH1602_H



//**************************************************************************************************
// Choose your platform
//**************************************************************************************************

#define STM32F10x											(0)
#define STM32F4xx											(1)

#define PLATFORM											(STM32F4xx)



//**************************************************************************************************
// Includes
//**************************************************************************************************

#if (PLATFORM == STM32F10x)
// Get RCC functions from standard peripheral library
#include "stm32f10x_rcc.h"

// Get GPIO functions from standard peripheral library
#include "stm32f10x_gpio.h"
#endif // #if (PLATFORM == STM32F10x)

#if (PLATFORM == STM32F4xx)
// Get RCC functions from standard peripheral library
#include "stm32f4xx_rcc.h"

// Get GPIO functions from standard peripheral library
#include "stm32f4xx_gpio.h"
#endif // #if (PLATFORM == STM32F4xx)



//**************************************************************************************************
// Declarations and definitions
//**************************************************************************************************

#if (PLATFORM == STM32F4xx)
// Define TRUE, FALSE and bool if not defined
#if (BOOL_IS_DEFINED == 0)
typedef enum {FALSE = 0, TRUE = !FALSE} bool;
#define BOOL_IS_DEFINED								(1)
#endif // #if (BOOL_IS_DEFINED == 0)
#endif // #if (PLATFORM == STM32F4xx)

// Configure which GPIO are in use

// If GPIOA is in use set this constant TRUE
#define GPIOA_IS_IN_USE								(TRUE)

// If GPIOB is in use set this constant TRUE
#define GPIOB_IS_IN_USE								(TRUE)

// If GPIOC is in use set this constant TRUE
#define GPIOC_IS_IN_USE								(TRUE)

// If GPIOD is in use set this constant TRUE
#define GPIOD_IS_IN_USE								(TRUE)

// If GPIOE is in use set this constant TRUE
#define GPIOE_IS_IN_USE								(TRUE)



// Select which pins are connected to the WH1602 module

// Set RS port
#define MT_WH1602_RS_PORT							(GPIOC)								
// Set RS pin
#define MT_WH1602_RS_PIN							(GPIO_Pin_2)

// Set RW port
#define MT_WH1602_RW_PORT							(GPIOB)	
// Set RW pin
#define MT_WH1602_RW_PIN							(GPIO_Pin_10)

// Set E port
#define MT_WH1602_E_PORT							(GPIOB)	
// Set E pin
#define MT_WH1602_E_PIN					  		(GPIO_Pin_14)

// Set DB7 port
#define MT_WH1602_DB7_PORT						(GPIOD)	
// Set DB7 pin
#define MT_WH1602_DB7_PIN	 						(GPIO_Pin_2)

// Set DB6 port
#define MT_WH1602_DB6_PORT						(GPIOC)	
// Set DB6 pin
#define MT_WH1602_DB6_PIN							(GPIO_Pin_12)

// Set DB5 port
#define MT_WH1602_DB5_PORT						(GPIOA)
// Set DB5 pin
#define MT_WH1602_DB5_PIN							(GPIO_Pin_8)

// Set DB4 port
#define MT_WH1602_DB4_PORT						(GPIOA)
// Set DB4 pin
#define MT_WH1602_DB4_PIN							(GPIO_Pin_10)

// Set DB3 port
#define MT_WH1602_DB3_PORT						(GPIOA)
// Set DB3 pin
#define MT_WH1602_DB3_PIN							(GPIO_Pin_15)

// Set DB2 port
#define MT_WH1602_DB2_PORT						(GPIOD)
// Set DB2 pin
#define MT_WH1602_DB2_PIN							(GPIO_Pin_11)

// Set DB1 port
#define MT_WH1602_DB1_PORT						(GPIOA)
// Set DB1 pin	
#define MT_WH1602_DB1_PIN							(GPIO_Pin_3)

// Set DB0 port
#define MT_WH1602_DB0_PORT						(GPIOA)
// Set DB0 pin
#define MT_WH1602_DB0_PIN							(GPIO_Pin_5)

// Delay us function constants
#define MT_WH1602_DELAY_uS						(10000000)
// Delay value for strob impulse
#define MT_WH1602_DATA_RW_DELAY				(2)

// Bit masks for different bits in byte
#define BIT_7_MASK										(0x80)
#define BIT_6_MASK										(0x40)
#define BIT_5_MASK										(0x20)
#define BIT_4_MASK										(0x10)
#define BIT_3_MASK										(0x08)
#define BIT_2_MASK										(0x04)
#define BIT_1_MASK										(0x02)
#define BIT_0_MASK										(0x01)

// MT_WH1602_Library function prototypes
extern void MT_WH1602_Init(void);
extern void MT_WH1602_Delay(uint32_t time);
extern void MT_WH1602_DataReadWrite(void);
extern void MT_WH1602_ClearDisplay(void);
extern void MT_WH1602_ReturnHome(void);
extern void MT_WH1602_EntryModeSet(bool IDaddress, bool shift);
extern void MT_WH1602_DisplayOnOff(bool Dbit, bool Cbit, bool Bbit);
extern void MT_WH1602_CursorOrDisplayShift(bool SCbit, bool RLbit);
extern void MT_WH1602_FunctionSet(bool DLbit, bool Nbit, bool Fbit);
extern void MT_WH1602_SetCGRAMAddress(uint8_t address);
extern void MT_WH1602_SetDDRAMAddress(uint8_t address);
extern bool MT_WH1602_ReadBusy(void);
extern void MT_WH1602_WriteData(uint8_t data);

#endif // #ifndef MT_WH1602_H

//****************************************** end of file *******************************************
