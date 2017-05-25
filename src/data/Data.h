#ifndef DATA
#define DATA

#include <stdlib.h>
#include <stdbool.h>

#define NB_ARDUINO 2
#define NB_DISTANCE_SENSOR_I 3
#define NB_DISTANCE_SENSOR_E 3
#define NB_MOTOR 3

#define DELIM_CHAR ":"

typedef enum ArduinoFunction ArduinoFunction;
enum ArduinoFunction {INTERN_ARDUINO, EXTERN_ARDUINO};

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
