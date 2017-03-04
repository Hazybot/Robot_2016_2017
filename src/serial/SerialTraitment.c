#include "SerialTraitment.h"

int openArduino(int* arduino, int nb){
	char* name = "/dev/ttyACM";
	int* tempArduino = calloc(nb, sizeof(int));
	int i;
	int success = 0;
	for(i = 0; (i < 10) && (success < nb); i++){
		int file;
		char* port = (char*) calloc(strlen(name)+1, sizeof(char));
		sprintf(port, "%s%d", name, i);
		file = open_s(port);
		if(file != -1){
			tempArduino[success] = file;
			success++;
		}
		free(port);
	}

	if(i >= 10){
		closeArduino(tempArduino, nb);
		free(tempArduino);
		printf("Can't open arduino\n");
		return -1;
	}

	arduino[MOTOR_ARDUINO] = tempArduino[0];

	free(tempArduino);
	return 0;
}

void closeArduino(int* arduino, int nb){
	int i;
	for(i = 0; i < nb; i++){
		close_s(arduino[i]);
	}
}
