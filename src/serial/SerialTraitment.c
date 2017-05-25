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

	for(i = 0; i < nb; i++){
		char* init = calloc(2, sizeof(char));
		init[0] = 'i';
		write_s(tempArduino[i], (uint8_t*) init, 1);
		read(tempArduino[i], init, 1);
		switch(init[0]){
			case 'i':
				arduino[INTERN_ARDUINO] = tempArduino[i];
				#ifdef DEBUG
					printf("Arduino moteur détecté\n");
				#endif
				break;
			case 'e':
				arduino[EXTERN_ARDUINO] = tempArduino[i];
				#ifdef DEBUG
					printf("Arduino capteur détecté\n");
				#endif
				break;
		}
		arduino[i] = tempArduino[i];
	}
	free(tempArduino);
	return 0;
}

void closeArduino(int* arduino, int nb){
	int i;
	for(i = 0; i < nb; i++){
		close_s(arduino[i]);
	}
}
