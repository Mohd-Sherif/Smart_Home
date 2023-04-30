/*
 * Keypad.c
 *
 * Created: 06/10/2021 02:25:11 PM
 *  Author: Mohamed Sherif
 */ 

#include "Keypad.h"
#include "../../MCAL/DioDriver/DIO.h"

static const unsigned char character[4][4]={ {'7','8','9','/'} , {'4','5','6','*'} , {'1','2','3','-'} , {'C','0','=','+'} };
//static const unsigned char character[4][4]={ {'1','2','3','+'} , {'4','5','6','-'} , {'7','8','9','*'} , {'C','0','=','/'} };

void Keypad_vinit(){
	unsigned char i;
	DIO_vsetport_dir(KEYPAD_PORT,0x0f);
	for(i=4;i<=7;i++)DIO_vpullupEN(KEYPAD_PORT,i,1);
}

unsigned char Keypad_u8read(){
	unsigned char row,col;
	for(row=0;row<=3;row++){
		DIO_vwritepin(KEYPAD_PORT,0,1);
		DIO_vwritepin(KEYPAD_PORT,1,1);
		DIO_vwritepin(KEYPAD_PORT,2,1);
		DIO_vwritepin(KEYPAD_PORT,3,1);
		DIO_vwritepin(KEYPAD_PORT,row,0);
		for(col=0;col<=3;col++)if(DIO_u8readpin(KEYPAD_PORT,col+4)==0)return character[row][col];
	}
	return NOT_PRESSED;
}
