#ifndef MAIN_H
#define MAIN_H

/* Include Variable and configuration marco */
#include "configuration.h"

/* Delare variable to using as global variable */
bool isReadingAccelerometer;
struct AccelerometerReading accelerometerReading;
RingBuffer metricsRingBuffer;
bool sensorToggle;
struct AngularPosition angularPosition;
bool isReadingGyroscope;
struct GyroscopeReading gyroscopeReading;
bool i2cHasProblem;
bool i2cInUse;
bool i2cTransmitting;
uint32_t i2cMisunderstoodEvents;

/* the address to identify the peripheral we are communicating with */
uint8_t peripheralAddress;

/* the buffer for the characters to be sent */
uint8_t outgoing[10];
uint8_t expectedNumberOfOutgoing;
uint8_t outgoingIndex;

/* the buffer for the characters to be received */
uint8_t incoming[10];
uint8_t expectedNumberOfIncoming;
uint8_t incomingIndex;

struct MagnetometerReading magnetometerReading;
uint32_t clearWarningsOnSecondsElapsed;
float channel1Pulse;
float channel2Pulse;
float channel3Pulse;
float channel4Pulse;
struct PWMInput pwmInputTimer4;
struct PWMInput pwmInputTimer5;
struct PWMInput pwmInputTimer9;
struct PWMInput pwmInputTimer12;
// Store throttle
struct PWMInput* throttle;

struct PWMInput* remotePidProportional;

struct PWMInput* remotePidIntegral;

struct PWMInput* resetAngularPosition;
uint32_t secondsElapsed;
uint32_t intermediateMillis;

/* Lib function to control and monitor quadcopter */
#include "accelerometer.h"
#include "analytics.h"
#include "angular_position.h"
#include "configuration.h"
#include "delay.h"
#include "gyroscope.h"
#include "i2c.h"
#include "on_board_leds.h"
#include "panic.h"
#include "pid.h"
#include "pwm.h"
#include "remote_controls.h"
#include "stm32f4xx.h"
#include "systick.h"

#endif
