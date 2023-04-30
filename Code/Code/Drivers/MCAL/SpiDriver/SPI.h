/*
 * SPI.h
 *
 * Created: 27-Aug-22 10:08:41 PM
 *  Author: Mohamed Sherif
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../DioDriver/DIO.h"
#include "../StandardMacrosHeader/std_macros.h"

#ifndef SPI_H_
#define SPI_H_

void SPI_Master_init();
void SPI_Slave_init();
unsigned char SPI_Master_Transmit_char(unsigned char data);
//void SPI_Master_Transmit_char();
unsigned char SPI_Slave_Receive_char(unsigned char data);
void SPI_Master_Transmit_String(unsigned char*ptr);

#endif /* SPI_H_ */