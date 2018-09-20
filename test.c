#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int DEBUG = 0;
const int DEBUG2 = 0;

// cacheline node node for singly linked LL
typedef struct cacheLine{
	long int tag;
	long int address;
	struct cacheLine *next;
} cacheLine;

int main(int argc, char **argv){

	if(argc <= 0){
		printf("error, too few args\n");
		return 0;	
	}

	if(DEBUG){ printf("initiliazed\n"); }

	FILE *fileInput;
	fileInput = stdin;
	
	// if file does not exist
	if(!fileInput){
		printf("error, no stdin\n");
		return 0;
	}

	char line[60];

	if(fgets(line, 60, fileInput) != NULL){
		printf("line is: \n%s\n", line);	
	}

	// reset file
	fclose(fileInput);

	return 0;

}
