#include "SerialTraitment.h"

#include <iostream>

using namespace std;

int openArduino(int* arduino, int nb){
	int* tempArduino = (int*) calloc(nb, sizeof(int));
	int i;
	int success = 0;
	for(i = 0; (i < 10) && (success < nb); i++){
		int file;
		char port[10];
		sprintf(port, "/dev/ttyACM%d", i);
		file = open_s(port, 0);
		if(file != -1){
			tempArduino[success] = file;
			success++;
		}
		//free(port);
		char port2[10];
                	sprintf(port2, "/dev/ttyUSB%d", i);
			file = open_s(port2, 1);
                	if(file != -1){
                        	tempArduino[success] = file;
                	        success++;
        	        }
	                //free(port);


	}

	if(i >= 10){
		closeArduino(tempArduino, nb);
		free(tempArduino);
		printf("Can't open arduino\n");
		return -1;
	}

	for(i = 0; i < nb; i++){
		char* init = (char*) calloc(2, sizeof(char));
		init[0] = 'i';
		write_s(tempArduino[i], (uint8_t*) init, 1);
		read_s(tempArduino[i], (uint8_t*) init, 1);
		switch(init[0]){
			case 'i':
				arduino[INTERN_ARDUINO] = tempArduino[i];
				#ifdef DEBUG
					printf("Arduino interne détecté\n");
				#endif
				break;
			case 'e':
				arduino[EXTERN_ARDUINO] = tempArduino[i];
				#ifdef DEBUG
					printf("Arduino externe détecté\n");
				#endif
				break;
			default:
				printf("JHQSJKDHQSJKDH %c\n", init[0]);
		}
		//arduino[i] = tempArduino[i];
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
