#ifndef REMOTE_CONTROLS_H_
#define REMOTE_CONTROLS_H_

#include "configuration.h"
#include "pwm_input.h"

void InitialiseRemoteControls(void);			// Function to initialize remote controls

/* These will come back as a percentage */
float ReadRemoteThrottle(void);					// Read value of throttle

float ReadRemotePidProportional(void);			// Read value of PID proportional

float ReadRemotePidIntegral(void);				// Read value of PID Integral

float ReadResetAngularPosition(void);			// Read value of position of angular at reset

#endif
