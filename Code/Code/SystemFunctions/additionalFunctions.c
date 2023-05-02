/*
 * additionalFunctions.c
 *
 * Created: 29-Apr-23 6:20:06 AM
 *  Author: Mohamed Sherif
 */ 

#include "../Config.h"

void setPassword(char mode){
	unsigned char keypadReadValue, passwordLocationCounter = 0, password[PASS_SIZE];
	if(mode == SHEFO){
		LCD_vsend_string("Set Shefo Pass");
	}
	else{
		LCD_vsend_string("Set GUEST Pass");
	}
	LCD_vmove_cursor(2, 1);
	LCD_vsend_string("Password: ");
	do{
		do{
			keypadReadValue = Keypad_u8read();
		}while(check(keypadReadValue) == NOT_PRESSED);
		LCD_vsend_char(keypadReadValue);
		password[passwordLocationCounter] = keypadReadValue;
		passwordLocationCounter++;
		_delay_ms(PASS_DELAY);
		LCD_vmove_cursor(2, 10 + passwordLocationCounter);
		LCD_vsend_char(PASS_SYMBOL);
	}while(passwordLocationCounter < PASS_SIZE);
	if(mode == SHEFO){
		EEPROM_vwriteBlock(EEPROM_SHEFO_STATUS_LOC + 1, password, PASS_SIZE);
		EEPROM_vwriteByte(EEPROM_SHEFO_STATUS_LOC, PASS_SET);
	}
	else{
		EEPROM_vwriteBlock(EEPROM_GUEST_STATUS_LOC + 1, password, PASS_SIZE);
		EEPROM_vwriteByte(EEPROM_GUEST_STATUS_LOC, PASS_SET);
	}
	LCD_vCLR_screen();
	LCD_vsend_string("Password Saved");
	LCD_vmove_cursor(2, 1);
	LCD_vsend_string("Successfully");
	_delay_ms(LCD_DELAY);
	LCD_vCLR_screen();
}
