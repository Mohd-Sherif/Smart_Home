/*
 * LED.h
 *
 * Created: 18/09/2021 04:39:25 PM
 *  Author: Mohamed Sherif
 */ 

#ifndef LED_H_
#define LED_H_

/*
Function Name        : LED_vinit
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Initialize the pin as an output pin to connect the LED.
*/
void LED_vinit(unsigned char port,unsigned char pin);

/*
Function Name        : LED_vON
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Turn on the LED connected to the given pin and port.
*/
void LED_vON(unsigned char port,unsigned char pin);

/*
Function Name        : LED_vOFF
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Turn off the LED connected to the given pin and port.
*/
void LED_vOFF(unsigned char port,unsigned char pin);

/*
Function Name        : LED_vtog
Function Returns     : void
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Toggle the LED connected to the given pin and port.
*/
void LED_vtog(unsigned char port,unsigned char pin);

/*
Function Name        : LED_u8read
Function Returns     : unsigned char
Function Arguments   : unsigned char port,unsigned char pin
Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
unsigned char LED_u8read(unsigned char port,unsigned char pin);

#endif /* LED_H_ */