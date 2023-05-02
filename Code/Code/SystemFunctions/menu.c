/*
 * menu.c
 *
 * Created: 29-Apr-23 6:19:19 AM
 *  Author: Mohamed Sherif
 */ 

#include "../Config.h"

void firstLogin(){
	LCD_vsend_string("First login ...");
	_delay_ms(LCD_DELAY);
	LCD_vCLR_screen();
	setPassword(SHEFO);
	setPassword(GUEST);
	EEPROM_vwriteByte(EEPROM_BLOCK_STATUS_LOC, FALSE);
}

