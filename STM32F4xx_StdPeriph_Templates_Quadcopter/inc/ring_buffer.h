#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include "configuration.h"

void  InitialiseRingBuffer(RingBuffer *_this);				// InitialiseRingBuffer
int RingBufferIsEmpty(RingBuffer *_this);					// Check buffer empty
int RingBufferIsFull(RingBuffer *_this);					// Check buffer full
uint16_t RingBufferPop(RingBuffer *_this);					// Pop data which don't need anymore
void RingBufferPut(RingBuffer *_this, uint16_t value);		// Put new data

#endif
