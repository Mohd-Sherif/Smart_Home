/*
 * Keypad.h
 *
 * Created: 06/10/2021 02:25:30 PM
 *  Author: Mohamed Sherif
 */ 

#define KEYPAD_PORT 'D'
#define NOT_PRESSED 0xff

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*
Function Name        : Keypad_vinit
Function Returns     : void
Function Arguments   : void
Function Description : initiate the Keypad.
*/
void Keypad_vinit();

/*
Function Name        : Keypad_u8read
Function Returns     : unsigned char
Function Arguments   : void
Function Description : Returns pressed value.
*/
unsigned char Keypad_u8read();

#endif /* KEYPAD_H_ */