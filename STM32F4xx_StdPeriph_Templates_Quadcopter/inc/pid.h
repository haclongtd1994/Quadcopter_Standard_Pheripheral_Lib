#ifndef PID_H_
#define PID_H_

#include "configuration.h"

// Function to initialize pid
struct Pid InitialisePid(float proportional, float integral, float differential);

// Calculate PID Adj
float CalculatePidAdjustment(Pid* pid, float current, float target);

#endif
