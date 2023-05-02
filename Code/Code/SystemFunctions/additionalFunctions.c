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

unsigned char check(unsigned char keypadReadValue){
	unsigned char returnValue;
	if(
	keypadReadValue == '+' ||
	keypadReadValue == '-' ||
	keypadReadValue == '/' ||
	keypadReadValue == '*' ||
	keypadReadValue == 'C' ||
	keypadReadValue == '=')
	{
		returnValue = NOT_PRESSED;
	}
	else{
		returnValue = keypadReadValue;
	}
	return returnValue;
}

void blockMode(){
	unsigned char i = BLOCK_PERIOD;
	LED_vON(BLOCK_LED_PORT, BLOCK_LED_PIN);
	LCD_vsend_string("Login is Blocked");
	LCD_vmove_cursor(2, 1);
	LCD_vsend_string("Wait 30 Seconds");
	for(i=BLOCK_PERIOD-1; i>0; --i){
		_delay_ms(1000);
		LCD_vmove_cursor(2, 6);
		LCD_vsend_char((i/10) + 48);
		LCD_vsend_char((i%10) + 48);
	}
	LCD_vCLR_screen();
	EEPROM_vwriteByte(EEPROM_BLOCK_STATUS_LOC, FALSE);
	LED_vOFF(BLOCK_LED_PORT, BLOCK_LED_PIN);
}

void login(){
	unsigned char keypadReadValue, passResult = TRUE, triesUsed = 0;
	do{
		LCD_vsend_string("Select User:");
		LCD_vmove_cursor(2, 1);
		LCD_vsend_string("0:Shefo 1:Guest");
		do{
			keypadReadValue = Keypad_u8read();
		}while(keypadReadValue != SHEFO && keypadReadValue != GUEST);
		LCD_vCLR_screen();
		triesUsed++;
		_delay_ms(PASS_DELAY);
		passResult = checkPass(keypadReadValue);
		if(passResult == FALSE){
			LCD_vCLR_screen();
			LCD_vsend_string("Wrong Password!");
			LCD_vmove_cursor(2, 1);
			LCD_vsend_string("Tries Left: ");
			LCD_vsend_char((MAX_TRIES - triesUsed) + 48);
			_delay_ms(LCD_DELAY);
			LCD_vCLR_screen();
		}
		if(triesUsed == MAX_TRIES){
			break;
		}
	}while(passResult == FALSE);
	if(triesUsed == MAX_TRIES){
		EEPROM_vwriteByte(EEPROM_BLOCK_STATUS_LOC, TRUE);
	}
	else if(keypadReadValue == SHEFO){
		shefoMenu();
	}
	else{
		guestMenu();
	}
}

unsigned char checkPass(unsigned char keypadReadValue){
	unsigned char password[PASS_SIZE], passwordLocationCounter = 0, result = TRUE, passwordRead[PASS_SIZE];
	if(keypadReadValue == SHEFO){
		LCD_vsend_string("Write Shefo");
		LCD_vmove_cursor(2, 1);
		LCD_vsend_string("Password: ");
		for(passwordLocationCounter = 0; passwordLocationCounter<PASS_SIZE; ++passwordLocationCounter){
			do{
				keypadReadValue = Keypad_u8read();
			}while(check(keypadReadValue) == NOT_PRESSED);
			LCD_vsend_char(keypadReadValue);
			password[passwordLocationCounter] = keypadReadValue;
			_delay_ms(PASS_DELAY);
			LCD_vmove_cursor(2, 10 + passwordLocationCounter + 1);
			LCD_vsend_char(PASS_SYMBOL);
		}
		LCD_vCLR_screen();
		EEPROM_u8readBlock(EEPROM_SHEFO_STATUS_LOC + 1, passwordRead, PASS_SIZE);
		for(passwordLocationCounter = 0; passwordLocationCounter<PASS_SIZE; ++passwordLocationCounter){
			if(password[passwordLocationCounter] != passwordRead[passwordLocationCounter]){
				result = FALSE;
				break;
			}
		}
	}
	else{
		LCD_vsend_string("Write Guest");
		LCD_vmove_cursor(2, 1);
		LCD_vsend_string("Password: ");
		for(passwordLocationCounter = 0; passwordLocationCounter<PASS_SIZE; ++passwordLocationCounter){
			do{
				keypadReadValue = Keypad_u8read();
			}while(check(keypadReadValue) == NOT_PRESSED);
			LCD_vsend_char(keypadReadValue);
			password[passwordLocationCounter] = keypadReadValue;
			_delay_ms(PASS_DELAY);
			LCD_vmove_cursor(2, 10 + passwordLocationCounter + 1);
			LCD_vsend_char(PASS_SYMBOL);
		}
		LCD_vCLR_screen();
		EEPROM_u8readBlock(EEPROM_GUEST_STATUS_LOC + 1, passwordRead, PASS_SIZE);
		for(passwordLocationCounter = 0; passwordLocationCounter<PASS_SIZE; ++passwordLocationCounter){
			if(password[passwordLocationCounter] != passwordRead[passwordLocationCounter]){
				result = FALSE;
				break;
			}
		}
	}
	return result;
}
