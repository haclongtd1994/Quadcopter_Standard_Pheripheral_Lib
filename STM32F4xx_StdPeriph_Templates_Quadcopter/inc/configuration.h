
#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

/* Include som lib standard */
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/* -------------------- CONFIGURATION ----------------- */
// ARMING_SEQUENCE
#define ARMING_SEQUENCE_LOW_THROTTLE_REQUIRED		0
#define ARMING_SEQUENCE_HIGH_THROTTLE_REQUIRED		1
#define ARMING_SEQUENCE_LOW_THROTTLE_REQUIRED_AGAIN 2
#define ARMING_SEQUENCE_ARMED						3

#define ARMING_SEQUENCE_IS_DISABLED					0

// THROTTLE CALIBRATION
/* use different values of motor speed if the quad ascends / descends too quickly with a centered throttle */
#define MOTOR_SPEED_REQUIRED_FOR_LIFT				1100.0

/* use different values of sensitivity if the quad ascends / descends too quickly when changing the throttle.
 * this is used in a calculation MOTOR_SPEED + (SENS. * THROTTLE) where THROTTLE is in the range -50 : +50.
 */
#define THROTTLE_SENSITIVITY						10.0

// PID
/* any pid calculations outside these bounds will be reduced to the bound value */
#define PID_MINIMUM_BOUND							-100.0
#define PID_MAXIMUM_BOUND							100.0


// MOTOR SPEED
#define MINIMUM_MOTOR_SPEED							1000
#define MAXIMUM_MOTOR_SPEED							2000


// ANGULAR POSITION
#define HOW_MUCH_I_TRUST_THE_GYROSCOPE     			0.98f
#define HOW_MUCH_I_TRUST_THE_ACCELEROMETER			1 - HOW_MUCH_I_TRUST_THE_GYROSCOPE
#define GYROSCOPE_SAMPLE_RATE              			1.0f / (1000.0f / 1.0f)	/* sample rate is closer to 1.74k per second now that time is not measured */


// ANALYTICS
#define ANALYTICS_FLUSH_FREQUENCY 		   			1000 / 200 	/* how often to flush the metrics (20 times per second) */
#define	ANALYTICS_CHARACTERS_TO_SEND_PER_FLUSH 		5

// METRICS
#define METRIC_SECONDS_ELAPSED								0
#define METRIC_LOOP_FREQUENCY								1
#define METRIC_GYROSCOPE_X_POSITION							2
#define METRIC_GYROSCOPE_Y_POSITION							3
#define METRIC_GYROSCOPE_Z_POSITION							4
#define METRIC_GYROSCOPE_TEMPERATURE						5
#define METRIC_GYROSCOPE_SAMPLE_RATE						6
#define METRIC_ACCELEROMETER_X_POSITION						7
#define METRIC_ACCELEROMETER_Y_POSITION						8
#define METRIC_ACCELEROMETER_Z_POSITION						9
#define METRIC_ACCELEROMETER_SAMPLE_RATE					10
#define METRIC_ANGULAR_X_POSITION							11
#define METRIC_ANGULAR_Y_POSITION							12
#define METRIC_ANGULAR_Z_POSITION							13
#define METRIC_PID_X_ADJUSTMENT								14
#define METRIC_PID_Y_ADJUSTMENT								15
#define METRIC_REMOTE_PID_PROPORTIONAL						16
#define METRIC_REMOTE_PID_INTEGRAL							27
#define METRIC_REMOTE_THROTTLE								17
#define METRIC_PROPELLOR_B_SPEED							18
#define METRIC_PROPELLOR_E_SPEED							19
#define METRIC_PROPELLOR_C_SPEED							20
#define METRIC_PROPELLOR_A_SPEED							21
#define METRIC_METRICS_BUFFER_SIZE							22
#define METRIC_DEBUG_VALUE_1								23
#define METRIC_DEBUG_VALUE_2								24
#define METRIC_DEBUG_VALUE_3								25
#define METRIC_DEBUG_VALUE_4								26

#define YELLOW_LED GPIO_Pin_12
#define ORANGE_LED GPIO_Pin_13
#define RED_LED    GPIO_Pin_14
#define BLUE_LED   GPIO_Pin_15


/* -------------------- Accelerometer Var ----------------- */
extern bool isReadingAccelerometer;


typedef struct AccelerometerReading {
	float x;
	float y;
	float z;
	float xG;
	float yG;
	float zG;
	float xOffset;
	float yOffset;
	float zOffset;
	uint32_t readings;
}AccelerometerReading;

extern struct AccelerometerReading accelerometerReading;

/* -------------------- Analytics Var ----------------- */

// Variable size of buffer ring
#define RING_BUFFER_SIZE 1024

// Struct to store data
typedef struct RingBuffer
{
	uint16_t buffer[RING_BUFFER_SIZE];
	int head;
	int tail;
	int count;
} RingBuffer;
extern RingBuffer metricsRingBuffer;


/* -------------------- Angular_Pos Var ----------------- */
extern bool sensorToggle;
typedef struct AngularPosition {
	float x;
	float y;
	float z;
}AngularPosition;

extern struct AngularPosition angularPosition;

/* -------------------- Gyroscope Var ----------------- */
extern bool isReadingGyroscope;

typedef struct GyroscopeReading {
	float x;
	float y;
	float z;
	float gyroscopeTemperature;
	float xOffset;
	float yOffset;
	float zOffset;
	uint32_t readings;
}GyroscopeReading;

extern struct GyroscopeReading gyroscopeReading;


/* -------------------- I2Ce Var ----------------- */
/* Note that this is not defined by the STM32 Peripheral Library, but is a case that I need to cover in my I2C interrupt function. */
#define I2C_EVENT_MASTER_BYTE_RECEIVED_AND_TRANSFER_FINISHED ((uint32_t)0x00030044)  /* BUSY, MSL, RXNE and BTF flags */


extern bool i2cHasProblem;
extern bool i2cInUse;
extern bool i2cTransmitting;
extern uint32_t i2cMisunderstoodEvents;

/* the address to identify the peripheral we are communicating with */
extern uint8_t peripheralAddress;

/* the buffer for the characters to be sent */
extern uint8_t outgoing[10];
extern uint8_t expectedNumberOfOutgoing;
extern uint8_t outgoingIndex;

/* the buffer for the characters to be received */
extern uint8_t incoming[10];
extern uint8_t expectedNumberOfIncoming;
extern uint8_t incomingIndex;

/* -------------------- Magnetometer Var ----------------- */
typedef struct MagnetometerReading {
	int16_t x;
	int16_t y;
	int16_t z;
}MagnetometerReading;

extern struct MagnetometerReading magnetometerReading;

/* -------------------- panic Var ----------------- */
extern uint32_t clearWarningsOnSecondsElapsed;

/* -------------------- Pid Var ----------------- */
/*
 * Proportional: relating to the present error
 * Integral: relating to the error over time
 * Derivative: relating to the prediction of future errors (based on the current rate of change)
 */
typedef struct Pid {
	float proportional;
	float integral;
	float differential;
	float lastError;
	float cumulativeError;
}Pid;

/* -------------------- Pwm Var ----------------- */
// Function pointer to get some info from channel
typedef void (*DutyCycleModifier)(float);
typedef void (*DutyCycleSetter)(float);
typedef float (*DutyCycleReader)();

extern float channel1Pulse;
extern float channel2Pulse;
extern float channel3Pulse;
extern float channel4Pulse;

// New structure to set return value
typedef struct DutyCycle {
	DutyCycleSetter set;
    DutyCycleModifier update;
    DutyCycleReader get;
}DutyCycle;

/* -------------------- pwm_input Var ----------------- */
// Struct data to manage PWM input
typedef struct PWMInput {
    volatile float dutyCycle;
    volatile float frequency;
    uint8_t hclckDivisor;

}PWMInput;

// Initialize 4 PWM input on board
extern struct PWMInput pwmInputTimer4;
extern struct PWMInput pwmInputTimer5;
extern struct PWMInput pwmInputTimer9;
extern struct PWMInput pwmInputTimer12;

/* -------------------- Remote control Var ----------------- */
// Store throttle
extern struct PWMInput* throttle;

extern struct PWMInput* remotePidProportional;

extern struct PWMInput* remotePidIntegral;

extern struct PWMInput* resetAngularPosition;


/* -------------------- SysTick Var ----------------- */
// 32 bit: this should be enough for about 68 years of continuous operation.
// note that if interrupts interrupt each other, this value may
// be relatively inaccurate regarding seconds elapsed.
extern uint32_t secondsElapsed;

// 32 bit: this should be enough for 49.7 days on continuous operation.
// note that if interrupts interrupt each other, this value may
// be relatively inaccurate regarding milliseconds elapsed.
extern uint32_t intermediateMillis;




#endif
