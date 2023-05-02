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

#endif /* CONFIG_H_ */