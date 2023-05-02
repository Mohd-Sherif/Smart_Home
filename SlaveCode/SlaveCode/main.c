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
    
	while(TRUE){
		request = SPI_Slave_Receive_char(DUMMY_DATA);
		switch(request){
			case ROOM1:
				if(LED_u8read(ROOM1_LED_PORT, ROOM1_LED_PIN) == 1){
					response = ON;
				}
				else{
					response = OFF;
				}
				SPI_Slave_Receive_char(response);
				request = SPI_Slave_Receive_char(DUMMY_DATA);
				_delay_ms(TRANSMISSION_DELAY);
				switch(request){
					case ON:
						LED_vON(ROOM1_LED_PORT, ROOM1_LED_PIN);
						break;
					case OFF:
						LED_vOFF(ROOM1_LED_PORT, ROOM1_LED_PIN);
						break;
				}
				break;
			case ROOM2:
				if(LED_u8read(ROOM2_LED_PORT, ROOM2_LED_PIN) == 1){
					response = ON;
				}
				else{
					response = OFF;
				}
				SPI_Slave_Receive_char(response);
				request = SPI_Slave_Receive_char(DUMMY_DATA);
				_delay_ms(TRANSMISSION_DELAY);
				switch(request){
					case ON:
						LED_vON(ROOM2_LED_PORT, ROOM2_LED_PIN);
						break;
					case OFF:
						LED_vOFF(ROOM2_LED_PORT, ROOM2_LED_PIN);
						break;
				}
				break;
			case ROOM3:
				if(LED_u8read(ROOM3_LED_PORT, ROOM3_LED_PIN) == 1){
					response = ON;
				}
				else{
					response = OFF;
				}
				SPI_Slave_Receive_char(response);
				request = SPI_Slave_Receive_char(DUMMY_DATA);
				_delay_ms(TRANSMISSION_DELAY);
				switch(request){
					case ON:
						LED_vON(ROOM3_LED_PORT, ROOM3_LED_PIN);
						break;
					case OFF:
						LED_vOFF(ROOM3_LED_PORT, ROOM3_LED_PIN);
						break;
				}
				break;
			case ROOM4:
				if(LED_u8read(ROOM4_LED_PORT, ROOM4_LED_PIN) == 1){
					response = ON;
				}
				else{
					response = OFF;
				}
				SPI_Slave_Receive_char(response);
				request = SPI_Slave_Receive_char(DUMMY_DATA);
				_delay_ms(TRANSMISSION_DELAY);
				switch(request){
					case ON:
						LED_vON(ROOM4_LED_PORT, ROOM4_LED_PIN);
						break;
					case OFF:
						LED_vOFF(ROOM4_LED_PORT, ROOM4_LED_PIN);
						break;
				}
				break;
			case TV:
				if(LED_u8read(TV_LED_PORT, TV_LED_PIN) == 1){
					response = ON;
				}
				else{
					response = OFF;
				}
				SPI_Slave_Receive_char(response);
				request = SPI_Slave_Receive_char(DUMMY_DATA);
				_delay_ms(TRANSMISSION_DELAY);
				switch(request){
					case ON:
						LED_vON(TV_LED_PORT, TV_LED_PIN);
						break;
					case OFF:
						LED_vOFF(TV_LED_PORT, TV_LED_PIN);
						break;
				}
				break;
			case AC:
				if(LED_u8read(AC_LED_PORT, AC_LED_PIN) == 1){
					response = ON;
				}
				else{
					response = OFF;
				}
				SPI_Slave_Receive_char(response);
				request = SPI_Slave_Receive_char(DUMMY_DATA);
				_delay_ms(TRANSMISSION_DELAY);
				switch(request){
					case ON:
						acStat = ON;
						LED_vON(AC_LED_PORT, AC_LED_PIN);
						break;
					case OFF:
						acStat = OFF;
						LED_vOFF(AC_LED_PORT, AC_LED_PIN);
						break;
				}
				break;
			case SET_TEMP:
				acTemperature = SPI_Slave_Receive_char(DUMMY_DATA);
				_delay_ms(TRANSMISSION_DELAY);
				break;
		}
    }
}

