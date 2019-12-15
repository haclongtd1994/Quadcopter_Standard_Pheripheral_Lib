#ifndef ANALYTICS_H_
#define ANALYTICS_H_

#include "configuration.h"
#include "ring_buffer.h"

void InitialiseAnalytics(void);

void RecordIntegerMetric(uint8_t type, uint8_t loopReference, uint32_t value);

void RecordFloatMetric(uint8_t type, uint8_t loopReference, float value);

void RecordPanicMessage(char *message);
void RecordWarningMessage(char *message);

void FlushMetrics(void);
void FlushAllMetrics(void);

#endif
