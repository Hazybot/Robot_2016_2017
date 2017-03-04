#ifndef DATA
#define DATA

#include <stdlib.h>
#include <stdbool.h>

#define NB_ARDUINO 1
#define NB_DISTANCE_SENSOR 5
#define NB_MOTOR 2

#define DELIM_CHAR ":"

typedef enum ArduinoFunction ArduinoFunction;
enum ArduinoFunction {MOTOR_ARDUINO};

typedef struct Data Data;
struct Data{
	bool stopped;
	int* arduino;
	float* distances;
	float* speeds;
};

Data* initialiseData();
void freeData(Data* data);

#endif
