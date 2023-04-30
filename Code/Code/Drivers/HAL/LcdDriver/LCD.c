/*
 * LCD.c
 *
 * Created: 03/10/2021 07:17:59 PM
 *  Author: Mohamed Sherif
 */ 

#include "../../MCAL/DioDriver/DIO.h"
#include "LCD.h"

void LCD_vinit(){
	_delay_ms(100);
	#if defined _8BIT_MODE
	
	DIO_vsetport_dir(DATA_PORT,0xff);
	DIO_vsetpin_dir(CMD_PORT,RS,1);
	DIO_vsetpin_dir(CMD_PORT,RW,1);
	DIO_vsetpin_dir(CMD_PORT,EN,1);
	DIO_vwritepin(CMD_PORT,RW,0);
	LCD_vsend_cmd(_8BITS);
	_delay_ms(1);
	LCD_vsend_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vsend_cmd(CLR_SCREEN);
	_delay_ms(5);
	LCD_vsend_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined _4BIT_MODE
	
	DIO_vsetport_dir(DATA_PORT,0xf0);
	DIO_vsetpin_dir(CMD_PORT,RS,1);
	DIO_vsetpin_dir(CMD_PORT,RW,1);
	DIO_vsetpin_dir(CMD_PORT,EN,1);
	DIO_vwritepin(CMD_PORT,RW,0);
	LCD_vsend_cmd(RETURN_HOME);
	_delay_ms(5);
	LCD_vsend_cmd(_4BITS);
	_delay_ms(1);
	LCD_vsend_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vsend_cmd(CLR_SCREEN);
	_delay_ms(5);
	LCD_vsend_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#endif
}

static void EN_pulse(){
	DIO_vwritepin(CMD_PORT,EN,1);
	_delay_ms(1);
	DIO_vwritepin(CMD_PORT,EN,0);
	_delay_ms(1);
}

void LCD_vsend_cmd(unsigned char cmd){
	#if defined _8BIT_MODE
	
	DIO_vwriteport(DATA_PORT,cmd);
	DIO_vwritepin(CMD_PORT,RS,0);
	EN_pulse();
	
	#elif defined _4BIT_MODE
	
	DIO_vwrite_HIGHnibble(DATA_PORT,cmd>>4);
	DIO_vwritepin(CMD_PORT,RS,0);
	EN_pulse();
	DIO_vwrite_HIGHnibble(DATA_PORT,cmd);
	DIO_vwritepin(CMD_PORT,RS,0);
	EN_pulse();
	
	#endif
}

void LCD_vsend_char(unsigned char data){
	#if defined _8BIT_MODE
	
	DIO_vwriteport(DATA_PORT,data);
	DIO_vwritepin(CMD_PORT,RS,1);
	EN_pulse();
	
	#elif defined _4BIT_MODE
	
	DIO_vwrite_HIGHnibble(DATA_PORT,data>>4);
	DIO_vwritepin(CMD_PORT,RS,1);
	EN_pulse();
	DIO_vwrite_HIGHnibble(DATA_PORT,data);
	DIO_vwritepin(CMD_PORT,RS,1);
	EN_pulse();
	
	#endif
}

void LCD_vsend_string(unsigned char* data){
	while(*data!='\0'){
		LCD_vsend_char(*data);
		data++;
	}
}

void LCD_vCLR_screen(){
	LCD_vsend_cmd(CLR_SCREEN);
	_delay_ms(5);
}

void LCD_vmove_cursor(signed char row,signed char coloumn){
	if(row>2||row<1||coloumn>16||coloumn<1)LCD_vsend_cmd(0x80);
	else if(row==1)LCD_vsend_cmd(0x80+coloumn-1);
	else if(row==2)LCD_vsend_cmd(0xc0+coloumn-1);
	_delay_ms(1);
}
