#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int DEBUG = 1;
const int DEBUG2 = 0;

typedef struct  _movieLine{
	char* color;
	char* director_name;
	int* num_critic_for_reviews;
	int* duration;
	int* director_facebook_likes;

} movieLine;
	


int main(int argc, char **argv){

	if(argc <= 0){
		printf("error, too few args\n");
		return 0;	
	}

	if(DEBUG){ printf("initiliazed\n"); }


	//FILE* input = stdin;
	
	char line[2000];
	char buffer;
	int lineCounter = 0;
	if(DEBUG) { printf("Will now read in lines\n"); }
	read(0, &buffer, 1);
	while(buffer != '\n'){
		printf("%c", buffer);
		line[lineCounter] = buffer;
		lineCounter++;
		read(0, &buffer, 1);
	}
	printf("\n");
	line[lineCounter] = '\0';
	//printf(line + '\n');
	printf("%s \n", line);
	printf("Output as shown with %d characters %c \n", lineCounter, line[lineCounter]);
	/*
	FILE *fileInput;
	fileInput = stdin;
	
	// if file does not exist
	if(feof(fileInput)){
		printf("error, no stdin\n");
		return 0;
	}

	char line[60];

	if(fgets(line, 60, fileInput) != NULL){
		printf("line is: \n%s\n", line);	
	}

	// reset file
	fclose(fileInput);
	*/


	return 0;

}
