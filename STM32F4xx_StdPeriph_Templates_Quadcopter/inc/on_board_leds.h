#ifndef ONBOARD_LEDS_H
#define ONBOARD_LEDS_H

#include "stm32f4xx_gpio.h"
#include "configuration.h"

void InitialiseLeds(void);			// Initialise Leds

void TurnOn(uint16_t leds);			// Turn on Led
void TurnOff(uint16_t leds);		// Turn off Led

#endif
