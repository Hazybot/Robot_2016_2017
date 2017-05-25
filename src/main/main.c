#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../serial/SerialTraitment.h"

int main(int argc, char** argv){

	Data* data = initialiseData();
	int test = openArduino(data->arduino, NB_ARDUINO) != 0;
	if(test != 0){
		freeData(data);
		return test;
	}
	
	while(1){
		char c;
		char buffer[150];
 
		printf("Entrez une chaine:\n");
		c = fgetc(stdin);
		
		switch(c){
			case 'u':
				write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "c", 1);
				read_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) buffer, 150);
				printf("Sensor extern : %s\n", buffer);
				
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "c", 1);
				read_s(data->arduino[INTERN_ARDUINO], (uint8_t*) buffer, 150);
				printf("Sensor intern : %s\n", buffer);
				break;
			case 'o':
				write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "o", 1);
				break;
			case 'c':
				write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "c", 1);
				break;
			case 'h':
				write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "h", 1);
				break;
			case 'v':
				write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "v", 1);
				break;
			case 'a':
				write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "a", 1);
				break;
			case 's':
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);
				break;
			case 'f':
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "f", 1);
				break;
			case 'r':
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "r", 1);
				break;
			case 'l':
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "l", 1);
				break;
		}
		
		
	}

	closeArduino(data->arduino, NB_ARDUINO);
	freeData(data);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
