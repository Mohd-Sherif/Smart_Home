/*
 * LED.c
 *
 * Created: 18/09/2021 04:39:04 PM
 *  Author: Mohamed Sherif
 */ 

#include "../../MCAL/DioDriver/DIO.h"

void LED_vinit(unsigned char port,unsigned char pin){
	DIO_vsetpin_dir(port,pin,1);
}

void LED_vON(unsigned char port,unsigned char pin){
	DIO_vwritepin(port,pin,1);
}

void LED_vOFF(unsigned char port,unsigned char pin){
	DIO_vwritepin(port,pin,0);
}

void LED_vtog(unsigned char port,unsigned char pin){
	DIO_vtogglepin(port,pin);
}

unsigned char LED_u8read(unsigned char port,unsigned char pin){
	return DIO_u8readpin(port,pin);
}
