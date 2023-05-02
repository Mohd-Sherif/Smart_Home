/*
 * Config.h
 *
 * Created: 29-Apr-23 3:20:09 AM
 *  Author: Mohamed Sherif
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

// MCAL Drivers
#include "Drivers/MCAL/StandardMacrosHeader/std_macros.h"
#include "Drivers/MCAL/DioDriver/DIO.h"
#include "Drivers/MCAL/EepromDriver/EEPROM.h"
#include "Drivers/MCAL/AdcDriver/ADC.h"
#include "Drivers/MCAL/TimerDriver/Timer.h"
#include "Drivers/MCAL/SpiDriver/SPI.h"

// HAL Drivers
#include "Drivers/HAL/LedDriver/LED.h"
#include "Drivers/HAL/LcdDriver/LCD.h"
#include "Drivers/HAL/KeypadDriver/Keypad.h"

// EEPROM
#define EEPROM_SHEFO_STATUS_LOC 0x22
#define EEPROM_GUEST_STATUS_LOC (EEPROM_SHEFO_STATUS_LOC + 1 + PASS_SIZE)
#define EEPROM_BLOCK_STATUS_LOC (EEPROM_GUEST_STATUS_LOC + 1 + PASS_SIZE)

// Status LEDs
#define BLOCK_LED_PORT 'A'
#define SHEFO_LED_PORT 'A'
#define GUEST_LED_PORT 'A'

#define BLOCK_LED_PIN 0
#define SHEFO_LED_PIN 1
#define GUEST_LED_PIN 2

// Slave LEDs
#define AC_LED_PORT 'D'
#define TV_LED_PORT 'D'
#define ROOM1_LED_PORT 'D'
#define ROOM2_LED_PORT 'D'
#define ROOM3_LED_PORT 'D'
#define ROOM4_LED_PORT 'D'

#define AC_LED_PIN 2
#define TV_LED_PIN 3
#define ROOM1_LED_PIN 4
#define ROOM2_LED_PIN 5
#define ROOM3_LED_PIN 6
#define ROOM4_LED_PIN 7

#endif /* CONFIG_H_ */