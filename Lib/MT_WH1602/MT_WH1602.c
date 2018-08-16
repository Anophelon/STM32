//**************************************************************************************************
// Filename							MT_WH1602.c
// Platform     				STM32F10x/STM32F4xx
// Author								Aveal (http://microtechnics.ru/)
// Current version  		1.0.0   
// Date         				07.03.2013
//**************************************************************************************************



//**************************************************************************************************
// Includes
//**************************************************************************************************

#include "MT_WH1602.h"



//**************************************************************************************************
// Declarations and definitions
//**************************************************************************************************

// GPIO initialization struct
GPIO_InitTypeDef MT_WH1602_GPIOcfg;



//**************************************************************************************************
// Global functions
//**************************************************************************************************



//**************************************************************************************************
// Function      MT_WH1602_Init()
// Description   GPIO initalization for WH1602 module
// Parameters    None
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_Init()
{
	// If GPIOA is in use
	#if (GPIOA_IS_IN_USE == TRUE)
	#if (PLATFORM == STM32F10x)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	#endif // #if (PLATFORM == STM32F4xx)
	#endif //	(GPIOA_IS_IN_USE == TRUE) 
	
	// If GPIOB is in use
	#if (GPIOB_IS_IN_USE == TRUE)
	#if (PLATFORM == STM32F10x)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	#endif // #if (PLATFORM == STM32F4xx)
	#endif //	(GPIOB_IS_IN_USE == TRUE) 
	
	// If GPIOC is in use
	#if (GPIOC_IS_IN_USE == TRUE)
	#if (PLATFORM == STM32F10x)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	#endif // #if (PLATFORM == STM32F4xx)
	#endif //	(GPIOC_IS_IN_USE == TRUE) 
	
	// If GPIOD is in use
	#if (GPIOD_IS_IN_USE == TRUE)
	#if (PLATFORM == STM32F10x)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	#endif // #if (PLATFORM == STM32F4xx)
	#endif //	(GPIOD_IS_IN_USE == TRUE) 
	
	// If GPIOE is in use
	#if (GPIOE_IS_IN_USE == TRUE)
	#if (PLATFORM == STM32F10x)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	#endif // #if (PLATFORM == STM32F4xx)
	#endif //	(GPIOE_IS_IN_USE == TRUE) 
	
	// Initialize all pins connected to the WH1602 module
	
	// RS pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_RS_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_RS_PORT, &MT_WH1602_GPIOcfg);
	
	// RW pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_RW_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_RW_PORT, &MT_WH1602_GPIOcfg);

	// E pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_E_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_E_PORT, &MT_WH1602_GPIOcfg);

	// DB7 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB7_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB7_PORT, &MT_WH1602_GPIOcfg);
	
	// DB6 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB6_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB6_PORT, &MT_WH1602_GPIOcfg);
	
	// DB5 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB5_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB5_PORT, &MT_WH1602_GPIOcfg);
	
	// DB4 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB4_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB4_PORT, &MT_WH1602_GPIOcfg);
	
	// DB3 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB3_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB3_PORT, &MT_WH1602_GPIOcfg);
	
	// DB2 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB2_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB2_PORT, &MT_WH1602_GPIOcfg);
	
	// DB1 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB1_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB1_PORT, &MT_WH1602_GPIOcfg);
	
	// DB0 pin initialization
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB0_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MT_WH1602_DB0_PORT, &MT_WH1602_GPIOcfg);	
} // End of MT_WH1602_Init()



//**************************************************************************************************
// Function      MT_WH1602_Delay()
// Description   Delay function
// Parameters    time - number of microseconds to wait
// RetVal	     	 None
//**************************************************************************************************
void MT_WH1602_Delay(uint32_t us) 
{
  volatile uint32_t i;
  RCC_ClocksTypeDef rcc;
	
  RCC_GetClocksFreq (&rcc);
  i = (rcc.HCLK_Frequency/MT_WH1602_DELAY_uS)*us;
	
  for (; i != 0; i--);
} // End of function MT_WH1602_Delay()



//**************************************************************************************************
// Function      MT_WH1602_DataReadWrite()
// Description   Strob impulse for data read/write
// Parameters    None
// RetVal	     	 None
//**************************************************************************************************
void MT_WH1602_DataReadWrite()
{
	GPIO_SetBits(MT_WH1602_E_PORT, MT_WH1602_E_PIN);
  MT_WH1602_Delay(MT_WH1602_DATA_RW_DELAY);
	GPIO_ResetBits(MT_WH1602_E_PORT, MT_WH1602_E_PIN);
} // End of function MT_WH1602_DataReadWrite()



//**************************************************************************************************
// Function      MT_WH1602_ClearDisplay()
// Description   This function clears the display
// Parameters    None
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_ClearDisplay()
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	GPIO_SetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_ClearDisplay()



//**************************************************************************************************
// Function      MT_WH1602_ReturnHome()
// Description   Cursor return home instruction
// Parameters    None
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_ReturnHome()
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	GPIO_SetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	GPIO_ResetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_ReturnHome()



//**************************************************************************************************
// Function      MT_WH1602_EntryModeSet()
// Description   Sets the moving direction of cursor and display
// Parameters    IDaddress - increase or decrease DDRAM address
//													 if IDaddress is "High" - DDRAM address is increased by 1
//													 if IDaddress is "Low" - DDRAM address is decreased by 1	
//							 shift		 - shift of entire display
//													 if shift is "Low" - shift of entire display is not performed
//													 if shift is "High" and IDaddress is "High" - shift the display to the left
//													 if shift is "High" and IDaddress is "Low" - shift the display to the right
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_EntryModeSet(bool IDaddress, bool shift)
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	GPIO_SetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	
	if (IDaddress == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	
	if (shift == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB0_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB0_PIN);
	}
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_EntryModeSet()



//**************************************************************************************************
// Function      MT_WH1602_DisplayOnOff()
// Description   Controls display/cursor/blink ON/OFF
// Parameters    Dbit - display ON/OFF control bit
//							 Cbit - cursor ON/OFF control bit 
//							 Bbit - cursor blink ON/OFF control bit
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_DisplayOnOff(bool Dbit, bool Cbit, bool Bbit)
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	GPIO_SetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	
	if (Dbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	
	if (Cbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	
	if (Bbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_DisplayOnOff()



//**************************************************************************************************
// Function      MT_WH1602_CursorOrDisplayShift()
// Description   Cursor return home instruction
// Parameters    SCbit 
//    					 RLbit 
//							 ----------------------------------------------------------------------------------
//							 SCbit | RLbit | Description 																										
//							 Low	 | Low   | Shift cursor to the left																							
//							 Low	 | High  | Shift cursor to the right
//							 High	 | Low   | Shift display to the left. Cursor follows the display shift		
//							 High	 | High  | Shift display to the right. Cursor follows the display shift	
//							 ----------------------------------------------------------------------------------			
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_CursorOrDisplayShift(bool SCbit, bool RLbit)
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	GPIO_SetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	
	if (SCbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	
	if (RLbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}

	GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	GPIO_ResetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_CursorOrDisplayShift()



//**************************************************************************************************
// Function      MT_WH1602_FunctionSet()
// Description   Sets interface data length and controls display line number and font type
// Parameters    DLbit - interface data length control bit 
//    					 Nbit  - display line number control bit
//         			 Fbit  - display font type control bit
//							 ----------------------------------------------------------------------------------
//							 SCbit | RLbit | Display Lines | Font | Duty factor 																								
//							 Low	 | Low   |		   1			 | 5x8	|			 1/8																
//							 Low	 | High  |		   1			 | 5x11 |			 1/11
//							 High	 | Low   |		   2			 | 5x8  |      1/16
//							 ----------------------------------------------------------------------------------			
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_FunctionSet(bool DLbit, bool Nbit, bool Fbit)
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	GPIO_SetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);

	if (DLbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	
	if (Nbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	
	if (Fbit == TRUE)
	{
		GPIO_SetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}

	GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	GPIO_ResetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_FunctionSet()



//**************************************************************************************************
// Function      MT_WH1602_SetCGRAMAddress()
// Description   Sets CGRAM address to AC
// Parameters    address - CGRAM address
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_SetCGRAMAddress(uint8_t address)
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_SetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	
	if (address & BIT_5_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	}
	
	if (address & BIT_4_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	
	if (address & BIT_3_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	
	if (address & BIT_2_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	
	if (address & BIT_1_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	
	if (address & BIT_0_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_SetCGRAMAddress()



//**************************************************************************************************
// Function      MT_WH1602_SetDDRAMAddress()
// Description   Sets CGRAM address to AC
// Parameters    address - DDRAM address
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_SetDDRAMAddress(uint8_t address)
{
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	GPIO_SetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	
	if (address & BIT_6_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	}
	
	if (address & BIT_5_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	}
	
	if (address & BIT_4_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	
	if (address & BIT_3_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	
	if (address & BIT_2_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	
	if (address & BIT_1_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	
	if (address & BIT_0_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_SetDDRAMAddress()



//**************************************************************************************************
// Function      MT_WH1602_ReadBusy()
// Description   Read busy flag and address
// Parameters    None
// RetVal	       busyFlag - busy flag current value
//**************************************************************************************************
bool MT_WH1602_ReadBusy()
{
	bool busyFlag;
	GPIO_ResetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_SetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
  
	// DB7 pin is input
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB7_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_IPD;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_IN;
	#endif // #if (PLATFORM == STM32F4xx)
	GPIO_Init(MT_WH1602_DB7_PORT, &MT_WH1602_GPIOcfg);
	
	GPIO_SetBits(MT_WH1602_E_PORT, MT_WH1602_E_PIN);
	MT_WH1602_Delay(MT_WH1602_DATA_RW_DELAY);
	busyFlag = (bool)GPIO_ReadInputDataBit(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	GPIO_ResetBits(MT_WH1602_E_PORT, MT_WH1602_E_PIN);
	
	// DB7 pin is output
	GPIO_StructInit(&MT_WH1602_GPIOcfg);
	MT_WH1602_GPIOcfg.GPIO_Pin = MT_WH1602_DB7_PIN;
	#if (PLATFORM == STM32F10x)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
	#endif // #if (PLATFORM == STM32F10x)
	#if (PLATFORM == STM32F4xx)
	MT_WH1602_GPIOcfg.GPIO_Mode = GPIO_Mode_OUT;
	#endif // #if (PLATFORM == STM32F4xx)
	GPIO_Init(MT_WH1602_DB7_PORT, &MT_WH1602_GPIOcfg);	
	
	return busyFlag;
} // End of function MT_WH1602_ReadBusy()



//**************************************************************************************************
// Function      MT_WH1602_WriteData()
// Description   Write data to CGRAM or DDRAM
// Parameters    data - 8-bit data byte
// RetVal	       None
//**************************************************************************************************
void MT_WH1602_WriteData(uint8_t data)
{	
	GPIO_SetBits(MT_WH1602_RS_PORT, MT_WH1602_RS_PIN);
	GPIO_ResetBits(MT_WH1602_RW_PORT, MT_WH1602_RW_PIN);
	
	if (data & BIT_7_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB7_PORT, MT_WH1602_DB7_PIN);
	}
  		
	if (data & BIT_6_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB6_PORT, MT_WH1602_DB6_PIN);
	}
	
	if (data & BIT_5_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB5_PORT, MT_WH1602_DB5_PIN);
	}
	
	if (data & BIT_4_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB4_PORT, MT_WH1602_DB4_PIN);
	}
	
	if (data & BIT_3_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB3_PORT, MT_WH1602_DB3_PIN);
	}
	
	if (data & BIT_2_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB2_PORT, MT_WH1602_DB2_PIN);
	}
	
	if (data & BIT_1_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB1_PORT, MT_WH1602_DB1_PIN);
	}
	
	if (data & BIT_0_MASK)
	{
		GPIO_SetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	else
	{
		GPIO_ResetBits(MT_WH1602_DB0_PORT, MT_WH1602_DB0_PIN);
	}
	
	MT_WH1602_DataReadWrite();
} // End of function MT_WH1602_WriteData()



//**************************************************************************************************
// Local functions
//**************************************************************************************************

// None.



//**************************************************************************************************
// Interrupts
//**************************************************************************************************

// None.



//****************************************** end of file *******************************************
