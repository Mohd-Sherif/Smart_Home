/*
 * EEPROM.h
 *
 * Created: 29/09/2021 03:57:12 PM
 *  Author: Mohamed Sherif
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

/*
Function Name        : EEPROM_vwriteByte
Function Returns     : void
Function Arguments   : unsigned short address,unsigned char data
Function Description : write one byte to the given address.
*/
void EEPROM_vwriteByte(unsigned short address,unsigned char data);

/*
	Function Name        : EEPROM_vWrite
	Function Returns     : void
	Function Arguments   : unsigned short address, unsigned char data, unsigned short size
	Function Description : Write block of bytes of the given size to EEPROM at the given address from the given array.
*/
void EEPROM_vwriteBlock(unsigned short address, unsigned char* data, unsigned short size);

/*
Function Name        : EEPROM_u8readByte
Function Returns     : unsigned char
Function Arguments   : unsigned short address
Function Description : read one byte from the given address.
*/
unsigned char EEPROM_u8readByte(unsigned short address);

/*
	Function Name        : EEPROM_u8eadBlock
	Function Returns     : void
	Function Arguments   : unsigned short address, unsigned char* distination, unsigned short size
	Function Description : Read block of bytes of the given size and save the result to given array.
*/
void EEPROM_u8readBlock(unsigned short address, unsigned char* distination, unsigned short size);

#endif /* EEPROM_H_ */