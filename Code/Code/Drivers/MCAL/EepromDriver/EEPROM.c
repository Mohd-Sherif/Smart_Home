/*
 * EEPROM.c
 *
 * Created: 29/09/2021 03:56:56 PM
 *  Author: Mohamed Sherif
 */ 
#include <avr/io.h>
#include "../StandardMacrosHeader/std_macros.h"

void EEPROM_vwriteByte(unsigned short address,unsigned char data){
	EEAR=address; //Set up address register
	//Another method:-
	//EEARL=(char)address;
	//EEARH=(char)(address>>8);
	EEDR=data; //Set up data register
	SET_BIT(EECR,EEMWE); //Write logical one to EEMWE
	SET_BIT(EECR,EEWE); //Start EEPROM write by setting EEWE
	while(READ_BIT(EECR,EEWE)); //Wait for completion of  write operation
}

void EEPROM_vwriteBlock(unsigned short address, unsigned char* data,unsigned short size){
	int i;
	for(i=0; i<size; ++i){
		EEPROM_vwriteByte(address + i, data[i]);
	}
}

unsigned char EEPROM_u8readByte(unsigned short address){
	EEAR=address; //Set up address register
	//Another method:-
	//EEARL=(char)address;
	//EEARH=(char)(address>>8);
	SET_BIT(EECR,EERE); //Start EEPROM read by setting EERE
	return EEDR; //Return data from data register
}

void EEPROM_u8readBlock(unsigned short address, unsigned char* distination, unsigned short size){
	int i;
	for(i=0; i<size; ++i){
		distination[i] = EEPROM_u8readByte(address + i);
	}
}
