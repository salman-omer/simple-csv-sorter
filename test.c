#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum { false, true } bool;

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
	movie-> num_critic_for_reviews = 0;
	movie-> duration = 0;
	movie-> director_facebook_likes = 0;
	movie-> actor_3_facebook_likes = 0;
	movie-> actor_2_name = NULL;
	movie-> actor_1_facebook_likes = 0;
	movie-> gross = 0;
	movie-> genres = NULL;
	movie-> actor_1_name = NULL;
	movie-> movie_title = NULL;
	movie-> num_voted_users = 0;
	movie-> cast_total_facebook_likes = 0;
	movie-> actor_3_name = NULL;
	movie-> facenumber_in_poster = 0;
	movie-> plot_keywords = NULL;
	movie-> movie_imdb_link = NULL;
	movie-> num_user_for_reviews = 0;
	movie-> language = NULL;
	movie-> country = NULL;
	movie-> content_rating = NULL;
	movie-> budget = 0;
	movie-> title_year = 0;
	movie-> actor_2_facebook_likes = 0;
	movie-> imdb_score = 0;
	movie-> aspect_ratio = 0;
	movie-> movie_facebook_likes = 0;
	movie->next = NULL;
	return 0;
}

/*
char* getColumnValue(movieLine* movie, char* columnName){
	if (strcmp(columnName, "color")){
		return movie->color;
	}
	else if (strcmp(columnName, "director_name")){
		return movie->director_name;
	}
	else if (strcmp(columnName, "num_critic_for_reviews")){
		int num = movie->num_critic_for_reviews;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "duration")){
		int num = movie->duration;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "director_facebook_likes")){
		int num = movie->director_facebook_likes;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;	
	}
	else if (strcmp(columnName, "actor_3_facebook_likes")){
		int num = movie->actor_3_facebook_likes;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "actor_2_name")){
		return movie->actor_2_name;
	}
	else if (strcmp(columnName, "actor_1_facebook_likes")){
		int num = movie->actor_1_facebook_likes;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "gross")){
		int num = movie->gross;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;	
	}
	else if (strcmp(columnName, "genres")){
		return movie->genres;
	}
	else if (strcmp(columnName, "actor_1_name")){
		return movie->actor_1_name;
	}
	else if (strcmp(columnName, "movie_title")){
		return movie->movie_title;
	}
	else if (strcmp(columnName, "num_voted_users")){
		int num = movie->num_voted_users;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "cast_total_facebook_likes")){
		int num = movie->cast_total_facebook_likes;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "actor_3_name")){
		 return movie->actor_3_name;
	}
	else if (strcmp(columnName, "facenumber_in_poster")){
		int num = movie->facenumber_in_poster;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "plot_keywords")){
		return movie->plot_keywords;
	}
	else if (strcmp(columnName, "movie_imdb_link")){
		return movie->movie_imdb_link;
	}
	else if (strcmp(columnName, "num_user_for_reviews")){
		int num = movie->num_user_for_reviews;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "language")){
		return movie->language;
	}
	else if (strcmp(columnName, "country")){
		return movie->country;
	}
	else if (strcmp(columnName, "content_rating")){
		return movie->content_rating;
	}
	else if (strcmp(columnName, "budget")){
		int num = movie->budget;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "title_year")){
		int num = movie->title_year;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "actor_2_facebook_likes")){
		int num = movie->actor_2_facebook_likes;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	else if (strcmp(columnName, "imdb_score")){
		int num = movie->imdb_score;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%f", num);
		return value;
	}
	else if (strcmp(columnName, "aspect_ratio")){
		int num = movie->aspect_ratio;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%f", num);
		return value;
	}
	else if (strcmp(columnName, "movie_facebook_likes")){
		int num = movie->movie_facebook_likes;
		char* value = malloc(20*sizeof(char));
		sprintf(value, "%d", num);
		return value;
	}
	return "Big problem here";
}

int* printMovieLineAsCsv(movieLine* movie, int numColumns, char** columnNames){
	char line[500];
	int lineIndex = 0;
	int i;
	int j;
	for (i = 0; i < numColumns; i++)
	{
		char* value = getColumnValue(movie, columnNames[i]);
		if(strcmp(columnNames[i], "num_critic_for_reviews") ||
			strcmp(columnNames[i], "director_facebook_likes") ||
			strcmp(columnNames[i], "actor_3_facebook_likes") ||
			strcmp(columnNames[i], "actor_2_facebook_likes") ||
			strcmp(columnNames[i], "actor_1_facebook_likes") ||
			strcmp(columnNames[i], "gross") ||
			strcmp(columnNames[i], "num_voted_users") ||
			strcmp(columnNames[i], "cast_total_facebook_likes") ||
			strcmp(columnNames[i], "facenumber_in_poster") ||
			strcmp(columnNames[i], "num_user_for_reviews") ||
			strcmp(columnNames[i], "budget") ||
			strcmp(columnNames[i], "title_year") ||
			strcmp(columnNames[i], "movie_facebook_likes")){
			if(atoi(value) == 0){
				if(i != numColumns - 1){
					line[lineIndex] = ',';
				} else {
					line[lineIndex] = '\0';
				}
				lineIndex++;
			} else {
				for(j = 0; j < strlen(value); j++){
					line[lineIndex] = value[j];
					lineIndex++;
				}
				if(i == numColumns - 1){
					line[lineIndex] = '\0';
					continue;
				}
				line[lineIndex] = ',';
				lineIndex ++;
			}
			continue;
		}
		if(strcmp(columnNames[i], "imdb_score") ||
			strcmp(columnNames[i], "aspect_ratio")){
			if (atof(value) == 0){
				if(i != numColumns - 1){
					line[lineIndex] = ',';
				} else {
					line[lineIndex] = '\0';
				}
				lineIndex++;
			} else {
				for(j = 0; j < strlen(value); j++){
					line[lineIndex] = value[j];
					lineIndex++;
				}
				if(i == numColumns - 1){
					line[lineIndex] = '\0';
					continue;
				}
				line[lineIndex] = ',';
				lineIndex ++;
			}
			continue;
		}
		for (j = 0; j < strlen(value); ++j)
		{
			line[lineIndex] = value[j];
			lineIndex++;
		}
		if(i != numColumns - 1){
			line[lineIndex] = ',';
		}
	}

	if (line[lineIndex] == ',')
	{
		line[lineIndex] = '\0';
	}

	printf("%s\n", line);
	return 0;
}

int printMoviesAsCsv(movieLineLL* LL, int numColumns, char** columnNames){
	movieLine* curr = LL->head;
	while(curr != NULL){
		printMovieLineAsCsv(curr, numColumns, columnNames);
		curr = curr->next;
	}
	return 0;
} */

int addFieldToMovie(int columnNumber, char** columnNames, movieLine* movie, char* value){
	char* columnName = columnNames[columnNumber];
	if(DEBUG){ printf("value %s\n", value);}
	if (strcmp(columnName, "color") == 0){
		movie->color = malloc(sizeof(char) * strlen(value));
		strcpy(movie->color, value);
		if (DEBUG) { printf("%s %d %s\n", "color", columnNumber, value); }
	}
	else if (strcmp(columnName, "director_name") == 0){
		movie->director_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->director_name, value);
		if (DEBUG) { printf("%s %s\n", "director_name", value); }
	}
	else if (strcmp(columnName, "num_critic_for_reviews") == 0){
		movie->num_critic_for_reviews = atoi(value);
		if (DEBUG) { printf("%s %d\n", "num_critic_for_reviews", atoi(value)); }
	}
	else if (strcmp(columnName, "duration") == 0){
		movie->duration = atoi(value);
		if (DEBUG) { printf("%s %d\n", "duration", atoi(value)); }
	}
	else if (strcmp(columnName, "director_facebook_likes") == 0){
		movie->director_facebook_likes = atoi(value);
		if (DEBUG) { printf("%s %d\n", "director_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_3_facebook_likes") == 0){
		movie->actor_3_facebook_likes = atoi(value);
		if (DEBUG) { printf("%s %d\n", "actor_3_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_2_name") == 0){
		movie->actor_2_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->actor_2_name, value);
		if (DEBUG) { printf("%s %s\n", "actor_2_name", value); }
	}
	else if (strcmp(columnName, "actor_1_facebook_likes") == 0){
		movie->actor_1_facebook_likes = atoi(value);
		if (DEBUG) { printf("%s %d\n", "actor_1_facebook_likes", atoi(value)); }

	}
	else if (strcmp(columnName, "gross") == 0){
		movie->gross = atoi(value);
		if (DEBUG) { printf("%s %d\n", "gross", atoi(value)); }
	}
	else if (strcmp(columnName, "genres") == 0){
		movie->genres = malloc(sizeof(char) * strlen(value));
		strcpy(movie->genres, value);
		if (DEBUG) { printf("%s %s\n", "genres", value); }
	}
	else if (strcmp(columnName, "actor_1_name") == 0){
		movie->actor_1_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->actor_1_name, value);
		if (DEBUG) { printf("%s %s\n", "actor_1_name", value); }
	}
	else if (strcmp(columnName, "movie_title") == 0){
		movie->movie_title = malloc(sizeof(char) * strlen(value));
		strcpy(movie->movie_title, value);
		if (DEBUG) { printf("%s %s\n", "movie_title", value); }
	}
	else if (strcmp(columnName, "num_voted_users") == 0){
		movie->num_voted_users = atoi(value);
		if (DEBUG) { printf("%s %d\n", "num_voted_users", atoi(value)); }
	}
	else if (strcmp(columnName, "cast_total_facebook_likes") == 0){
		movie->cast_total_facebook_likes = atoi(value);
		if (DEBUG) { printf("%s %d\n", "cast_total_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_3_name") == 0){
		movie->actor_3_name = malloc(sizeof(char) * strlen(value));
		strcpy(movie->actor_3_name, value);
		if (DEBUG) { printf("%s %s\n", "actor_3_name", value); }
	}
	else if (strcmp(columnName, "facenumber_in_poster") == 0){
		movie->facenumber_in_poster = atoi(value);
		if (DEBUG) { printf("%s %d\n", "facenumber_in_poster", atoi(value)); }
	}
	else if (strcmp(columnName, "plot_keywords") == 0){
		movie->plot_keywords = malloc(sizeof(char) * strlen(value));
		strcpy(movie->plot_keywords, value);
		if (DEBUG) { printf("%s %s\n", "plot_keywords", value); }
	}
	else if (strcmp(columnName, "movie_imdb_link") == 0){
		movie->movie_imdb_link = malloc(sizeof(char) * strlen(value));
		strcpy(movie->movie_imdb_link, value);
		if (DEBUG) { printf("%s %s\n", "movie_imdb_link", value); }
	}
	else if (strcmp(columnName, "num_user_for_reviews") == 0){
		movie->num_user_for_reviews = atoi(value);
		if (DEBUG) { printf("%s %d\n", "num_user_for_reviews", atoi(value)); }
	}
	else if (strcmp(columnName, "language") == 0){
		movie->language = malloc(sizeof(char) * strlen(value));
		strcpy(movie->language, value);
		if (DEBUG) { printf("%s %s\n", "language", value); }
	}
	else if (strcmp(columnName, "country") == 0){
		movie->country = malloc(sizeof(char) * strlen(value));
		strcpy(movie->country, value);
		if (DEBUG) { printf("%s %s\n", "country", value); }
	}
	else if (strcmp(columnName, "content_rating") == 0){
		movie->content_rating = malloc(sizeof(char) * strlen(value));
		strcpy(movie->content_rating, value);
		if (DEBUG) { printf("%s %s\n", "content_rating", value); }
	}
	else if (strcmp(columnName, "budget") == 0){
		movie->budget = atoi(value);
		if (DEBUG) { printf("%s %d\n", "budget", atoi(value)); }
	}
	else if (strcmp(columnName, "title_year") == 0){
		movie->title_year = atoi(value);
		if (DEBUG) { printf("%s %d\n", "title_year", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_2_facebook_likes") == 0){
		movie->actor_2_facebook_likes = atoi(value);
		if (DEBUG) { printf("%s %d\n", "actor_2_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "imdb_score") == 0){
		movie->imdb_score = atof(value);
		if (DEBUG) { printf("%s %f\n", "imdb_score", atof(value)); }
	}
	else if (strcmp(columnName, "aspect_ratio") == 0){
		movie->aspect_ratio = atof(value);
		if (DEBUG) { printf("%s %f\n", "aspect_ratio", atof(value)); }
	}
	else if (strcmp(columnName, "movie_facebook_likes") == 0){
		movie->movie_facebook_likes = atoi(value);
		if (DEBUG) { printf("%s %d\n", "movie_facebook_likes", atoi(value)); }
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
	if(DEBUG){ for(i = 0; i < numColumns; i++){ printf("column: %s at number %d\n", columnNames[i], i); } }

	// now want to read in a row and put appropriate data in fields for the row object
	// to read in a row, we start at new line or EOF
	
	//make a new struct, make previous struct point to it, populate it


	char currCellText[100];
	int currCellTextIndex = 0;
	int cellNumber = 0;	
	if(DEBUG2){ printf("Line %d\n", __LINE__);}
	movieLine* currMovie = malloc(sizeof(movieLine));
	initMovieLine(currMovie);
	movieLineLL* moviesLL = malloc(sizeof(movieLineLL));
	moviesLL->head = currMovie;
	moviesLL->rear = currMovie;
	moviesLL->size = 1;
	bool quotationMark = false;
	if(DEBUG2){ printf("Line %d\n", __LINE__);}
	while(read(0, &buffer, 1) != 0){
		if(buffer == '"'){
			quotationMark = !quotationMark;
			continue;
		}
		if (buffer == ',' && !quotationMark)
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

	//printMoviesAsCsv(moviesLL, numColumns, columnNames);


	return 0;

}