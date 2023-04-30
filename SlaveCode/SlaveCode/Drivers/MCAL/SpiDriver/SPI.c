/*
 * SPI.c
 *
 * Created: 27-Aug-22 10:07:36 PM
 *  Author: Mohamed Sherif
 */ 

#include "SPI.h"

void SPI_Master_init(){
	//Set MOSI, SCK and SS as output pins for Master
	DIO_vsetpin_dir('B',4,1);
	DIO_vsetpin_dir('B',5,1);
	DIO_vsetpin_dir('B',7,1);
	SET_BIT(SPCR,MSTR); //Enable Master Mode
	SET_BIT(SPCR,SPR0); //Set Clock to fosc/16
	SET_BIT(SPCR,SPE); //Enable SPI
	//SET_BIT(SPCR,SPIE); //Enable Interrupt
	DIO_vwritepin('B',4,1); //Set SS to High
}

void SPI_Slave_init(){
	SET_BIT(SPCR,SPE); //Enable SPI
	DIO_vsetpin_dir('B',6,1); //Set MISO as output pin for slave
}

unsigned char SPI_Master_Transmit_char(unsigned char data){
	DIO_vwritepin('B',4,0); //Clear SS to send data to slave
	SPDR=data; //Put data in SPDR
	while(READ_BIT(SPSR,SPIF)==0); //Wait until Transmission is finished
	return SPDR; //Read SPDR
}
/*
void SPI_Master_Transmit_char(){
	DIO_vwritepin('B',4,0); //Clear SS to send data to slave
	SPDR=data; //Put data in SPDR
}
*/
unsigned char SPI_Slave_Receive_char(unsigned char data){
	SPDR=data; //Put data in SPDR
	while(READ_BIT(SPSR,SPIF)==0); //Wait until Transmission is finished
	return SPDR; //Read received data
}

void SPI_Master_Transmit_String(unsigned char*ptr){
	while(*ptr!=0){
		SPI_Master_Transmit_char(*ptr);
		_delay_ms(300);
		ptr++;
	}
}