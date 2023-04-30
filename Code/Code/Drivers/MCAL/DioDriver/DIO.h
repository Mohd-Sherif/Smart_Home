/*
 * DIO.h
 *
 * Created: 15/09/2021 01:41:57 PM
 *  Author: Mohamed Sherif
 */ 

#ifndef DIO_H_
#define DIO_H_

/*
Function Name        : DIO_vsetpin_dir
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin,unsigned char direction
Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetpin_dir(unsigned char port,unsigned char pin,unsigned char direction);

/*
Function Name        : DIO_vwritepin
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin,unsigned char value
Function Description : Set the value of the given pin in the given port (value 0 = low : 1 = high)
*/
void DIO_vwritepin(unsigned char port,unsigned char pin,unsigned char value);

/*
Function Name        : DIO_vtogglepin
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_vtogglepin(unsigned char port,unsigned char pin);

/*
Function Name        : DIO_u8readpin
Function Returns     : unsigned char
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
unsigned char DIO_u8readpin(unsigned char port,unsigned char pin);

/*
Function Name        : DIO_vsetport_dir
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char direction
Function Description : set the direction of whole port .
*/
void DIO_vsetport_dir(unsigned char port,unsigned char direction);

/*
Function Name        : DIO_vwriteport
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char value
Function Description : Write the value to all port pins.
*/
void DIO_vwriteport(unsigned char port,unsigned char value);

/*
Function Name        : DIO_vtoggleport
Function Returns     : void
Function Arguments   : unsigned char port
Function Description : Toggle all port pins.
*/
void DIO_vtoggleport(unsigned char port);

/*
Function Name        : DIO_u8readport
Function Returns     : unsigned char
Function Arguments   : unsigned char port
Function Description : read the value of the port .
*/
unsigned char DIO_u8readport(unsigned char port);

/*
	Function Name        : DIO_vpullupEN
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char pin,unsigned char enable
     Function Description : Enable and disenable pull up resistor to the given pin at the given port 
*/
void DIO_vpullupEN(unsigned char port,unsigned char pin,unsigned char enable);

/*
	Function Name        : DIO_vwrite_LOWnibble
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char value
     Function Description : Write the number to the first 4 port pins.
*/
void DIO_vwrite_LOWnibble(unsigned char port,unsigned char value);

/*
	Function Name        : DIO_vwrite_HIGHnibble
	Function Returns     : void
	Function Arguments   : unsigned char port,unsigned char value
     Function Description : Write the number to the last 4 port pins.
*/
void DIO_vwrite_HIGHnibble(unsigned char port,unsigned char value);

#endif /* DIO_H_ */