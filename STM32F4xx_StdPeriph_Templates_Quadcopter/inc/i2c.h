
#ifndef I2C_H
#define I2C_H

#include "stm32f4xx_i2c.h"
#include "configuration.h"

// Function to read from address I2C
void ReadFromAddress(uint8_t peripheral, uint8_t periperalRegister, uint8_t numberOfBytesToRead);

// Function to wait bus free
void WaitUntilBusIsFree(void);

// Function reset I2c
void ResetI2C(void);

// Initialize i2c
void InitialiseI2C(void);

// Send start signal
void SendStart(void);

// Send address of object
void SendAddress(uint8_t address, uint8_t direction);

// Send data
void SendData(uint8_t data);

//Send stop signal
void SendStop(void);

#endif
