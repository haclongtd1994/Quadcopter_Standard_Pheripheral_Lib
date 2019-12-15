#ifndef TIMER_H
#define TIMER_H

#include "stm32f4xx_gpio.h"
#include "configuration.h"

void InitialisePWM(void);		// Initialize PWM
// Function initialize channel
DutyCycle InitialisePWMChannel(GPIO_TypeDef* GPIOx, uint16_t pin, uint8_t pinSource, uint8_t channel);

#endif
