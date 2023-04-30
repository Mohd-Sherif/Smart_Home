/*
 * Timer.h
 *
 * Created: 16-Aug-22 1:51:14 AM
 *  Author: Mohamed Sherif
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../StandardMacrosHeader/std_macros.h"

#ifndef TIMER_H_
#define TIMER_H_

void Timer_CTC_Interrupt();

void Timer_wave_nonPWM();

void Timer_wave_fastPWM();

void Timer_wave_phasecorrectPWM();

void Timer2_OVF_Interrupt();

void Timer1_wave_fastPWM(double val);

#endif /* TIMER_H_ */