/*
 * ADC.c
 *
 * Created: 04-Jul-22 1:42:05 PM
 *  Author: Mohamed Sherif
 */ 

#include <avr/io.h>
#include "../StandardMacrosHeader/std_macros.h"

void ADC_vinit(void){
	// configure VREF as internal VREF of the ADC (2.56V)
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN); //enable ADC
	/*adjust ADC clock*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}

unsigned short ADC_u16read(void){
	unsigned short read_val;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC)); //wait until the conversion be done
	//another method for the waiting the conversion
	/*
	while(IS_BIT_CLR(ADCSRA,ADIF)); //stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); //clear ADIF
	*/
	read_val=ADCL;
	read_val|=(ADCH<<8);
	return read_val;
}
