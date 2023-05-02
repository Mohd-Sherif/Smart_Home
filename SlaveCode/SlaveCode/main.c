/*
 * SlaveCode.c
 *
 * Created: 29-Apr-23 7:06:20 PM
 * Author : Mohamed Sherif
 */ 

#include "../../Code/Code/Config.h"


int main(void)
{
	unsigned char request = DUMMY_DATA, response = DUMMY_DATA;
	
	
	ADC_vinit();
	
	LED_vinit(AC_LED_PORT, AC_LED_PIN);
	LED_vinit(TV_LED_PORT, TV_LED_PIN);
	LED_vinit(ROOM1_LED_PORT, ROOM1_LED_PIN);
	LED_vinit(ROOM2_LED_PORT, ROOM2_LED_PIN);
	LED_vinit(ROOM3_LED_PORT, ROOM3_LED_PIN);
	LED_vinit(ROOM4_LED_PORT, ROOM4_LED_PIN);
	
    SPI_Slave_init();
    
    }
}

