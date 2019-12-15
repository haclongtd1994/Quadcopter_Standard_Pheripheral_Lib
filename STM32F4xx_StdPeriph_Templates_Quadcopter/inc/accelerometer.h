
#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "configuration.h"
#include "i2c.h"

// Function to initialize Accelermeter
void InitialiseAccelerometer(void);

// Function to read value from i2c
void ReadAccelerometer(void);

#endif
