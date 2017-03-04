#include "Data.h"

Data* initialiseData(){
	Data* data = (Data*) malloc(sizeof(Data));

	data->stopped = false;

	data->arduino = (int*) calloc(NB_ARDUINO, sizeof(int));

	return data;
}

void freeData(Data* data){
	free(data);
}
