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

// System Functions Headers
#include "SystemFunctions/additionalFunctions.h"
#include "SystemFunctions/menu.h"


// System Configurations
#define PASS_NOT_SET 0xFF
#define PASS_SET 0x00
#define PASS_SYMBOL '*'
#define MAX_TRIES 3
#define PASS_DELAY 250
#define LCD_DELAY 1500
#define SHEFO '0'
#define GUEST '1'
#define INVALID 0
#define VALID 1
#define PASS_SIZE 4
#define TRUE 1
#define FALSE 0
#define BLOCK_PERIOD 30
#define TRANSMISSION_DELAY 250


// Status Codes for Communication
#define DUMMY_DATA 0x10
#define ROOM1 0x11
#define ROOM2 0x12
#define ROOM3 0x13
#define ROOM4 0x14
#define TV 0x15
#define AC 0x16
#define ON 0x17
#define OFF 0x18
#define SET_TEMP 0x19




#endif /* CONFIG_H_ */