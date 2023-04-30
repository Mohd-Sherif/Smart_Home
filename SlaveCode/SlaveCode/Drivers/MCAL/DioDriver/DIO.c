/*
 * DIO.c
 *
 * Created: 15/09/2021 01:42:13 PM
 *  Author: Mohamed Sherif
 */

#include <avr/io.h>
#include "../StandardMacrosHeader/std_macros.h"

void DIO_vsetpin_dir(unsigned char port,unsigned char pin,unsigned char direction){
	switch(port){
		case 'A':
		case 'a':
			if(direction==0)CLR_BIT(DDRA,pin); //Set the direction of the given pin in port A as input
			else SET_BIT(DDRA,pin); //Set the direction of the given pin in port A as output
			break;
		case 'B':
		case 'b':
			if(direction==0)CLR_BIT(DDRB,pin); //Set the direction of the given pin in port B as input
			else SET_BIT(DDRB,pin); //Set the direction of the given pin in port B as output
			break;
		case 'C':
		case 'c':
			if(direction==0)CLR_BIT(DDRC,pin); //Set the direction of the given pin in port C as input
			else SET_BIT(DDRC,pin); //Set the direction of the given pin in port C as output
			break;
		case 'D':
		case 'd':
			if(direction==0)CLR_BIT(DDRD,pin); //Set the direction of the given pin in port D as input
			else SET_BIT(DDRD,pin); //Set the direction of the given pin in port D as output
			break;
	}
}

void DIO_vwritepin(unsigned char port,unsigned char pin,unsigned char value){
	switch(port){
		case 'A':
		case 'a':
			if(value==0)CLR_BIT(PORTA,pin); //Set the value of the given pin in port A as Low
			else SET_BIT(PORTA,pin); //Set the value of the given pin in port A as High
			break;
		case 'B':
		case 'b':
			if(value==0)CLR_BIT(PORTB,pin); //Set the value of the given pin in port B as Low
			else SET_BIT(PORTB,pin); //Set the value of the given pin in port B as High
			break;
		case 'C':
		case 'c':
			if(value==0)CLR_BIT(PORTC,pin); //Set the value of the given pin in port C as Low
			else SET_BIT(PORTC,pin); //Set the value of the given pin in port C as High
			break;
		case 'D':
		case 'd':
			if(value==0)CLR_BIT(PORTD,pin); //Set the value of the given pin in port D as low
			else SET_BIT(PORTD,pin); //Set the value of the given pin in port D as High
			break;
	}
}

void DIO_vtogglepin(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
		case 'a':
			TOG_BIT(PORTA,pin); //Toggle the value of the given pin in port A
			break;
		case 'B':
		case 'b':
			TOG_BIT(PORTB,pin); //Toggle the value of the given pin in port B
			break;
		case 'C':
		case 'c':
			TOG_BIT(PORTC,pin); //Toggle the value of the given pin in port C
			break;
		case 'D':
		case 'd':
			TOG_BIT(PORTD,pin); //Toggle the value of the given pin in port D
			break;
	}
}

unsigned char DIO_u8readpin(unsigned char port,unsigned char pin){
	char value;
	switch(port){
		case 'A':
		case 'a':
			value=READ_BIT(PINA,pin); //Read the value from the given pin in port A
			break;
		case 'B':
		case 'b':
			value=READ_BIT(PINB,pin); //Read the value from the given pin in port B
			break;
		case 'C':
		case 'c':
			value=READ_BIT(PINC,pin); //Read the value from the given pin in port C
			break;
		case 'D':
		case 'd':
			value=READ_BIT(PIND,pin); //Read the value from the given pin in port D
			break;
	}
	return value;
}

void DIO_vsetport_dir(unsigned char port,unsigned char direction){
	switch(port){
		case 'A':
		case 'a':
			DDRA=direction; //Set the direction of port A
			break;
		case 'B':
		case 'b':
			DDRB=direction; //Set the direction of port B
			break;
		case 'C':
		case 'c':
			DDRC=direction; //Set the direction of port C
			break;
		case 'D':
		case 'd':
			DDRD=direction; //Set the direction of port D
			break;
	}
}

void DIO_vwriteport(unsigned char port,unsigned char value){
	switch(port){
		case 'A':
		case 'a':
			PORTA=value; //Write the given value to the port A
			break;
		case 'B':
		case 'b':
			PORTB=value; //Write the given value to the port B
			break;
		case 'C':
		case 'c':
			PORTC=value; //Write the given value to the port C
			break;
		case 'D':
		case 'd':
			PORTD=value; //Write the given value to the port D
			break;
	}
}

void DIO_vtoggleport(unsigned char port){
	switch(port){
		case 'A':
		case 'a':
			PORTA=~PORTA; //Toggle Port A
			break;
		case 'B':
		case 'b':
			PORTB=~PORTB; //Toggle Port B
			break;
		case 'C':
		case 'c':
			PORTC=~PORTC; //Toggle Port C
			break;
		case 'D':
		case 'd':
			PORTD=~PORTD; //Toggle Port D
			break;
	}
}

unsigned char DIO_u8readport(unsigned char port){
	char value;
	switch(port){
		case 'A':
		case 'a':
			value=PINA; //read the value of port A
			break;
		case 'B':
		case 'b':
			value=PINB; //read the value of port B
			break;
		case 'C':
		case 'c':
			value=PINC; //read the value of port C
			break;
		case 'D':
		case 'd':
			value=PIND; //read the value of port D
			break;
	}
	return value;
}

void DIO_vpullupEN(unsigned char port,unsigned char pin,unsigned char enable){
	switch(port){
		case 'A':
		case 'a':
			if(enable==0)CLR_BIT(PORTA,pin); //Set the value of the given pin in port A as Low
			else SET_BIT(PORTA,pin); //Set the value of the given pin in port A as High
			break;
		case 'B':
		case 'b':
			if(enable==0)CLR_BIT(PORTB,pin); //Set the value of the given pin in port B as Low
			else SET_BIT(PORTB,pin); //Set the value of the given pin in port B as High
			break;
		case 'C':
		case 'c':
			if(enable==0)CLR_BIT(PORTC,pin); //Set the value of the given pin in port C as Low
			else SET_BIT(PORTC,pin); //Set the value of the given pin in port C as High
			break;
		case 'D':
		case 'd':
			if(enable==0)CLR_BIT(PORTD,pin); //Set the value of the given pin in port D as Low
			else SET_BIT(PORTD,pin); //Set the value of the given pin in port D as High
			break;
	}
}

void DIO_vwrite_LOWnibble(unsigned char port,unsigned char value){
	value&=0x0f;
	switch(port)
	{
		case 'A':
			PORTA&=0xf0;
			PORTA|=value;
			break;
		case 'B':
			PORTB&=0xf0;
			PORTB|=value;
			break;
		case 'C':
			PORTC&=0xf0;
			PORTC|=value;
			break;
		case 'D':
			PORTD&=0xf0;
			PORTD|=value;
			break;
	}
}

void DIO_vwrite_HIGHnibble(unsigned char port,unsigned char value){
	value<<=4;
	switch(port)
	{
		case 'A':
		case 'a':
			PORTA&=0x0f;
			PORTA|=value;
			break;
		case 'B':
		case 'b':
			PORTB&=0x0f;
			PORTB|=value;
			break;
		case 'C':
		case 'c':
			PORTC&=0x0f;
			PORTC|=value;
			break;
		case 'D':
		case 'd':
			PORTD&=0x0f;
			PORTD|=value;
			break;
	}
}
