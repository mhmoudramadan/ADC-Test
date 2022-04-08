/*
 * main.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Dell
 */
#include"LIB/LSTD_TYPES.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"MCAL/MGIE/MGIE_Interface.h"
#include"MCAL/MADC/MADC_Interface.h"
#include"HAL/HCLCD/HCLCD_Config.h"
#include"HAL/HCLCD/HCLCD_Interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	/*LCD PIN init*/
	MDIO_Errorstate_SetPinDirection(MDIO_PORTA,PIN4,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTA,PIN5,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTA,PIN6,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTA,PIN7,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RS_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RW_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,E_PIN,PIN_OUTPUT);
	/*LCD int*/
	HAL_VidHCLCD_4BitModeInit();
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"welcome..");
	_delay_ms(1000);
	HAL_VidHCLCD_4BitModeSendCommand(0x01);
	HAL_VidHCLCD_4BitModeSetPosition(1,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"ADC READING");
    MDIO_Errorstate_SetPinDirection(MDIO_PORTA,PIN1,PIN_INPUT);
	/*ADC*/

	MADC_VidSingleConversion_Init();
	uint16 Loc_uint16Digital;
	uint16 Loc_uint16AnalogPrev=0;
	uint16 Loc_uint16Analog;
	HAL_VidHCLCD_4BitModeSetPosition(2,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"Volt=");
	HAL_VidHCLCD_4BitModeSetPosition(2,9);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"MV");


	while(1)
	{
		MADC_VidADCStartSingleConversion(1);
		Loc_uint16Digital=MADC_uint16Read();
		Loc_uint16Analog=(Loc_uint16Digital*5000UL)/1024; 
		if(Loc_uint16Analog!=Loc_uint16AnalogPrev)
		{
		HAL_VidHCLCD_4BitModeSetPosition(2,5);
		HAL_VidHCLCD_4BitModeWriteNumber(Loc_uint16Analog);
		Loc_uint16AnalogPrev=Loc_uint16Analog;
		HAL_VidHCLCD_4BitModeSetPosition(2,11);
		}
		else
		{
			// Do nothing
		}
	}
	return 0;
}
