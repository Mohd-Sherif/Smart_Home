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

void shefoMenu(){
	unsigned char keypadReadValue, response;
	LED_vON(SHEFO_LED_PORT, SHEFO_LED_PIN);
	LCD_vsend_string("Welcome Shefo!");
	_delay_ms(LCD_DELAY);
	while(TRUE){
		do{
			LCD_vCLR_screen();
			LCD_vsend_string("1:ROOM1  2:ROOM2");
			LCD_vmove_cursor(2, 1);
			LCD_vsend_string("3:ROOM3  4:More");
			_delay_ms(250);
			do{
				keypadReadValue = Keypad_u8read();
				if(keypadReadValue == 'C'){
					break;
				}
			}while(keypadReadValue < '1' || keypadReadValue > '4');
			LCD_vCLR_screen();
			if(keypadReadValue == 'C'){
				break;
			}
			switch(keypadReadValue){
				case '1':
					LCD_vsend_string("ROOM1 STAT: ");
					response = room(1);
					break;
				case '2':
					LCD_vsend_string("ROOM2 STAT: ");
					response = room(2);
					break;
				case '3':
					LCD_vsend_string("ROOM3 STAT: ");
					response = room(3);
					break;
				case '4':
					LCD_vCLR_screen();
					LCD_vsend_string("1:ROOM4  2:TV");
					LCD_vmove_cursor(2, 1);
					LCD_vsend_string("3:AC  4:Return");
					_delay_ms(250);
					do{
						keypadReadValue = Keypad_u8read();
					}while(keypadReadValue < '1' || keypadReadValue > '4');
					LCD_vCLR_screen();
					switch(keypadReadValue){
						case '1':
							LCD_vsend_string("ROOM4 STAT: ");
							response = room(4);
							break;
						case '2':
							LCD_vsend_string("TV STAT: ");
							response = tv();
							break;
						case '3':
							LCD_vsend_string("1:Set Temp.");
							LCD_vmove_cursor(2, 1);
							LCD_vsend_string("2:Set AC");
							do{
								keypadReadValue = Keypad_u8read();
							}while(keypadReadValue < '1' || keypadReadValue > '2');
							LCD_vCLR_screen();
							switch(keypadReadValue){
								case '1':
									setTemp();
									keypadReadValue = '4';
									break;
								case '2':
									LCD_vsend_string("AC STAT: ");
									response = ac();
									break;
							}
							break;
					}
					break;
			}
		}while(keypadReadValue == '4');
		if(keypadReadValue == 'C'){
			break;
		}
		statusPage(response);
	}
	LED_vOFF(SHEFO_LED_PORT, SHEFO_LED_PIN);
}
