/*
 * Timer.c
 *
 * Created: 16-Aug-22 1:50:52 AM
 *  Author: Mohamed Sherif
 */ 

#include "Timer.h"

void Timer_CTC_Interrupt(){
	SET_BIT(TCCR0,WGM01); //Select CTC Mode
	OCR0=80; //Load value in OCR0
	//Select Timer Clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//Enable Interrupt
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void Timer_wave_nonPWM(){
	SET_BIT(DDRB,3); //Set OC0 as output pin
	SET_BIT(TCCR0,WGM01); //Select CTC mode
	OCR0=64; //Load a value in OCR0
	//Select timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00); //Toggle OC0 on compare match
}

void Timer_wave_fastPWM(){
	SET_BIT(DDRB,3); //Set OC0 as Output pin
	//Select Fast PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	OCR0=64; //Load value in OCR0
	//Select Timer Clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//Set OC0 at Compare Match, Clear OC0 at Bottom, (Inverting Mode)
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*
	//Clear OC0 at Compare Match, Set OC0 at Bottom, (non-Inverting Mode)
	SET_BIT(TCCR0,COM01);
	*/
}

void Timer_wave_phasecorrectPWM(){
	SET_BIT(DDRB,3); //Set OC0 as Output pin
	SET_BIT(TCCR0,WGM00); //Select Fast PWM
	OCR0=64; //Load value in OCR0
	//Select Timer Clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//Set OC0 on Compare Match when up-counting, Clear OC0 on Compare Match when down-counting
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*
	//Clear OC0 on Compare Match when up-counting, Set OC0 on Compare Match when down-counting
	SET_BIT(TCCR0,COM01);
	*/
}

void Timer2_OVF_Interrupt(){
	SET_BIT(ASSR,AS2); //Select Timer Clock
	//Select Timer Clock
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	//Enable Interrupt
	sei();
	SET_BIT(TIMSK,TOIE2);
}

void Timer1_wave_fastPWM(double val){
	SET_BIT(DDRD,5); //Set OCA1 as output pin
	//Select Fast PWM mode
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	OCR1A=val*1000; //Load value in OCR1A
	ICR1=19999; //Load a value in ICR1
	SET_BIT(TCCR1B,CS10); //Select Timer Clock (no prescaling)
	SET_BIT(TCCR1A,COM1A1); //Clear OC1A on compare match, Set OC1A at Bottom, (non-inverting)
}
