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
	
    }
}
