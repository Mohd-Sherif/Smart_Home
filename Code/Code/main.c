/*
 * Code.c
 *
 * Created: 29-Apr-23 2:21:42 AM
 * Author : Mohamed Sherif
 */ 

#include "Config.h"

int main(void)
{	
    LCD_vinit();
	LCD_vsend_string("Welcome to Shefo");
	LCD_vmove_cursor(2, 1);
	LCD_vsend_string("Smart Home");
	_delay_ms(LCD_DELAY);
	LCD_vCLR_screen();

	Keypad_vinit();
	
	LED_vinit(BLOCK_LED_PORT, BLOCK_LED_PIN);
	LED_vinit(SHEFO_LED_PORT, SHEFO_LED_PIN);
	LED_vinit(GUEST_LED_PORT, GUEST_LED_PIN);
	
	SPI_Master_init();
	
	// First Time Opening the System Check
	if(EEPROM_u8readByte(EEPROM_SHEFO_STATUS_LOC) == PASS_NOT_SET ||
		EEPROM_u8readByte(EEPROM_GUEST_STATUS_LOC) == PASS_NOT_SET)
	{
		firstLogin();
	}
	
	// Beginning of the periodic behavior
    while(TRUE){
		if(EEPROM_u8readByte(EEPROM_BLOCK_STATUS_LOC) == TRUE){
			blockMode();
		}
		else{
			login();
		}
    }
}
