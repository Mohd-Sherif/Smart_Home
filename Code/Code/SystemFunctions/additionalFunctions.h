/*
 * additionalFunctions.h
 *
 * Created: 29-Apr-23 6:20:29 AM
 *  Author: Mohamed Sherif
 */ 


#ifndef ADDITIONALFUNCTIONS_H_
#define ADDITIONALFUNCTIONS_H_

unsigned char check(unsigned char keypadReadValue);
void setPassword(char mode);
void blockMode();
void login();
unsigned char checkPass(unsigned char keypadReadValue);

#endif /* ADDITIONALFUNCTIONS_H_ */