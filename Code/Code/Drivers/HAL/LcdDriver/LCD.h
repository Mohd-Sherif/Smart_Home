/*
 * LCD.h
 *
 * Created: 03/10/2021 07:18:17 PM
 *  Author: Mohamed Sherif
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#define _4BIT_MODE
#define DATA_PORT 'C'
#define CMD_PORT 'C'
#define RS 0
#define RW 1
#define EN 2
#define CURSOR_ON_DISPLAY_ON 0x0e
#define CLR_SCREEN 0x01
#define ENTRY_MODE 0x06
#define RETURN_HOME 0x02
#if defined _8BIT_MODE
#define _8BITS 0x38
#elif defined _4BIT_MODE
#define _4BITS 0x28
#endif

#ifndef LCD_H_
#define LCD_H_

/*
Function Name        : LCD_vinit
Function Returns     : void
Function Arguments   : void
Function Description : initiate the LCD.
*/
void LCD_vinit();

/*
Function Name        : EN_pulse
Function Returns     : static void
Function Arguments   : void
Function Description : produces the enable pulse.
*/
static void EN_pulse();

/*
Function Name        : LCD_vsend_cmd
Function Returns     : void
Function Arguments   : unsigned char cmd
Function Description : Send a command.
*/
void LCD_vsend_cmd(unsigned char cmd);

/*
Function Name        : LCD_vsend_char
Function Returns     : void
Function Arguments   : unsigned char data
Function Description : display a character.
*/
void LCD_vsend_char(unsigned char data);

/*
Function Name        : LCD_vsend_string
Function Returns     : void
Function Arguments   : unsigned char* data
Function Description : display a string.
*/
void LCD_vsend_string(unsigned char* data);

/*
Function Name        : LCD_vCLR_screen
Function Returns     : void
Function Arguments   : void
Function Description : clear the screen and move the cursor to the beginning of the LCD.
*/
void LCD_vCLR_screen();

/*
Function Name        : LCD_vmove_cursor
Function Returns     : void
Function Arguments   : signed char row,signed char coloumn
Function Description : move the cursor.
*/
void LCD_vmove_cursor(signed char row,signed char coloumn);

#endif /* LCD_H_ */