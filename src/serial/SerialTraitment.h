#ifndef SERIAL_TRAITMENT
#define SERIAL_TRAITMENT

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string>

#include "../data/Data.h"
#include "Serial.h"

int openArduino(int* arduino, int nb);
void closeArduino(int* arduino, int nb);

void* launchSerialLoop(void* data_void);

#endif
