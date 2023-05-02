/*
 * menu.h
 *
 * Created: 29-Apr-23 6:19:08 AM
 *  Author: Mohamed Sherif
 */ 


#ifndef MENU_H_
#define MENU_H_

void firstLogin();
void shefoMenu();
void guestMenu();
unsigned char room(unsigned char roomNumber);
unsigned char tv();
unsigned char ac();
void statusPage(unsigned char response);
void setTemp();

#endif /* MENU_H_ */