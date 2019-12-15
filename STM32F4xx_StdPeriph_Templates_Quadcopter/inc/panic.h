
#ifndef PANIC_H
#define PANIC_H

#include "configuration.h"

void InitialisePanicButton(void);
void ClearWarnings(void);

void panic(char* message);
void panicWithValue(char* message, uint32_t value);

void warning(char* message);
void warningWithValue(char* message, uint32_t value);


#endif
