#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int DEBUG = 2;
const int DEBUG2 = 0;

typedef struct  _movieLine{
	char* color;
	char* director_name;
	int num_critic_for_reviews;
	int duration;
	int director_facebook_likes;
	int actor_3_facebook_likes;
	char* actor_2_name;
	int actor_1_facebook_likes;
	int gross;
	char* genres;
	char* actor_1_name;
	char* movie_title;
	int num_voted_users;
	int cast_total_facebook_likes;
	char* actor_3_name;
	int facenumber_in_poster;
	char* plot_keywords;
	char* movie_imdb_link;
	int num_user_for_reviews;
	char* language;
	char* country;
	char* content_rating;
	int budget;
	int title_year;
	int actor_2_facebook_likes;
	double imdb_score;
	double aspect_ratio;
	int movie_facebook_likes;
	struct _movieLine* next;
} movieLine;

typedef struct _moveLineLL
{
	movieLine* head;
	movieLine* rear;
	int size;
} movieLineLL;

int initMovieLine(movieLine* movie){
	movie-> color = NULL;
	movie-> director_name = NULL;
	movie-> num_critic_for_reviews = -1;
	movie-> duration = -1;
	movie-> director_facebook_likes = -1;
	movie-> actor_3_facebook_likes = -1;
	movie-> actor_2_name = NULL;
	movie-> actor_1_facebook_likes = -1;
	movie-> gross = -1;
	movie-> genres = NULL;
	movie-> actor_1_name = NULL;
	movie-> movie_title = NULL;
	movie-> num_voted_users = -1;
	movie-> cast_total_facebook_likes = -1;
	movie-> actor_3_name = NULL;
	movie-> facenumber_in_poster = -1;
	movie-> plot_keywords = NULL;
	movie-> movie_imdb_link = NULL;
	movie-> num_user_for_reviews = -1;
	movie-> language = NULL;
	movie-> country = NULL;
	movie-> content_rating = NULL;
	movie-> budget = -1;
	movie-> title_year = -1;
	movie-> actor_2_facebook_likes = -1;
	movie-> imdb_score = -1;
	movie-> aspect_ratio = -1;
	movie-> movie_facebook_likes = -1;
}

int addFieldToMovie(int columnNumber, char** columnNames, movieLine* movie, char* value){
	char* columnName = columnNames[columnNumber];
	if(DEBUG){ printf("value %s\n", value);}
	if (strcmp(columnName, "color")){
		movie->color = malloc(sizeof(char) * strlen(value));
		strcpy(movie->color, value);
	}
	else if (strcmp(columnName, "director_name")){
		movie->director_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->director_name, value);
	}
	else if (strcmp(columnName, "num_critic_for_reviews")){
		movie->num_critic_for_reviews = atoi(value);
	}
	else if (strcmp(columnName, "duration")){
		movie->duration = atoi(value);
	}
	else if (strcmp(columnName, "director_facebook_likes")){
		movie->director_facebook_likes = atoi(value);
	}
	else if (strcmp(columnName, "actor_3_facebook_likes")){
		movie->actor_3_facebook_likes = atoi(value);
	}
	else if (strcmp(columnName, "actor_2_name")){
		movie->actor_2_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->actor_2_name, value);
	}
	else if (strcmp(columnName, "actor_1_facebook_likes")){
		movie->actor_1_facebook_likes = atoi(value);
	}
	else if (strcmp(columnName, "gross")){
		movie->gross = atoi(value);
	}
	else if (strcmp(columnName, "genres")){
		movie->genres = malloc(sizeof(char) * strlen(value));
		strcpy(movie->genres, value);
	}
	else if (strcmp(columnName, "actor_1_name")){
		movie->actor_1_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->actor_1_name, value);
	}
	else if (strcmp(columnName, "movie_title")){
		movie->movie_title = malloc(sizeof(char) * strlen(value));
		strcpy(movie->movie_title, value);
	}
	else if (strcmp(columnName, "num_voted_users")){
		movie->num_voted_users = atoi(value);
	}
	else if (strcmp(columnName, "cast_total_facebook_likes")){
		movie->cast_total_facebook_likes = atoi(value);
	}
	else if (strcmp(columnName, "actor_3_name")){
		movie->actor_3_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->actor_3_name, value);
	}
	else if (strcmp(columnName, "facenumber_in_poster")){
		movie->facenumber_in_poster = atoi(value);
	}
	else if (strcmp(columnName, "plot_keywords")){
		movie->plot_keywords = malloc(sizeof(char) * strlen(value));
		strcpy(movie->plot_keywords, value);
	}
	else if (strcmp(columnName, "movie_imdb_link")){
		movie->plot_keywords = malloc(sizeof(char) * strlen(value));
		strcpy(movie->plot_keywords, value);
	}
	else if (strcmp(columnName, "num_user_for_reviews")){
		movie->num_user_for_reviews = atoi(value);
	}
	else if (strcmp(columnName, "language")){
		movie->language = malloc(sizeof(char) * strlen(value));
		strcpy(movie->language, value);
	}
	else if (strcmp(columnName, "country")){
		movie->country = malloc(sizeof(char) * strlen(value));
		strcpy(movie->country, value);
	}
	else if (strcmp(columnName, "content_rating")){
		movie->content_rating = malloc(sizeof(char) * strlen(value));
		strcpy(movie->content_rating, value);
	}
	else if (strcmp(columnName, "budget")){
		movie->budget = atoi(value);
	}
	else if (strcmp(columnName, "title_year")){
		movie->title_year = atoi(value);
	}
	else if (strcmp(columnName, "actor_2_facebook_likes")){
		movie->actor_2_facebook_likes = atoi(value);
	}
	else if (strcmp(columnName, "imdb_score")){
		movie->imdb_score = atof(value);
	}
	else if (strcmp(columnName, "aspect_ratio")){
		movie->aspect_ratio = atof(value);
	}
	else if (strcmp(columnName, "movie_facebook_likes")){
		movie->movie_facebook_likes = atoi(value);
	}
	return 0;
}

int main(int argc, char **argv){

	if(argc <= 0){
		printf("error, too few args\n");
		return 0;	
	}

	if(DEBUG){ printf("initiliazed\n"); }


	//FILE* input = stdin;
	
	char columnsLine[2000];
	char buffer;
	int lineCounter = 0;
	if(DEBUG) { printf("Reading in first line\n"); }
	read(0, &buffer, 1);
	while(buffer != '\n'){
		printf("%c", buffer);
		columnsLine[lineCounter] = buffer;
		lineCounter++;
		read(0, &buffer, 1);
	}
	printf("\n");
	columnsLine[lineCounter] = '\0';
	
	// now want to parse the first line so that we know the number of columns
	// number of columns = # of commas + 1
	int i;
	int numColumns = 1;
	for(i = 0; i < strlen(columnsLine); i++){
		if(columnsLine[i] == ','){
			numColumns++;
		}
	}
	if(DEBUG) { printf("Number of columns is %d\n", numColumns);}

	// want to add each column header to an array of strings
	// array of strings of size numColumns, each string max size of 30, each index corresponds to that columns index
	char** columnNames;
	columnNames = malloc(numColumns * sizeof(char*));
	for(i = 0; i < numColumns; i++){
		columnNames[i] = malloc(30 * sizeof(char));
	}

	int currColumnNum = 0;
	int currStringIndex = 0;
	for(i = 0; i < strlen(columnsLine); i++){
		if(columnsLine[i] == ','){
			columnNames[currColumnNum][currStringIndex] = '\0';
			currColumnNum++;
			currStringIndex = 0;
			continue;
		}
		columnNames[currColumnNum][currStringIndex] = columnsLine[i];
		currStringIndex++;
	}

	// print out column names for testing
	if(DEBUG){ for(i = 0; i < numColumns; i++){ printf("column: %s\n", columnNames[i]); } }

	// now want to read in a row and put appropriate data in fields for the row object
	// to read in a row, we start at new line or EOF
	
	//make a new struct, make previous struct point to it, populate it


	char currCellText[100];
	int currCellTextIndex = 0;
	int cellNumber = 0;	
	if(DEBUG){ printf("Line %d\n", __LINE__);}
	movieLine* currMovie = malloc(sizeof(movieLine));
	initMovieLine(currMovie);
	movieLineLL* moviesLL = malloc(sizeof(movieLineLL));
	moviesLL->head = currMovie;
	moviesLL->rear = currMovie;
	moviesLL->size = 1;
	if(DEBUG){ printf("Line %d\n", __LINE__);}
	while(read(0, &buffer, 1) != 0){
		if (buffer == ',')
		{
			// fill out the struct field based on this info
			currCellText[currCellTextIndex] = '\0';
			currCellTextIndex = 0;
			addFieldToMovie(cellNumber, columnNames, currMovie, currCellText);
			cellNumber++;
			currCellText[0] = '\0';
			continue;
		}
		if(buffer == '\n'){
			// complete the current movie and make the next one
			currCellText[currCellTextIndex] = '\0';
			currCellTextIndex = 0;
			addFieldToMovie(cellNumber, columnNames, currMovie, currCellText);
			cellNumber = 0;
			currCellText[0] = '\0';

			movieLine* newMovie = malloc(sizeof(movieLine));
			initMovieLine(newMovie);
			moviesLL->rear = newMovie;
			currMovie->next = newMovie;
			currMovie = newMovie;
			continue;
		}

		currCellText[currCellTextIndex] = buffer;
		currCellTextIndex++;

	}

	// deal with the last character
	currCellText[currCellTextIndex] = '\0';
	addFieldToMovie(cellNumber, columnNames, currMovie, currCellText);




	return 0;

}