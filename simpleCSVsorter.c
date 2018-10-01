#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "simpleCSVsorter.h"

typedef enum { false, true } bool;

const int DEBUG = 0;
const int DEBUG2 = 0;

// arg: pointer to movieLine
// ret 0 if completed
// this function intializes all the values for a movieline pointer
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
	movie->next = NULL;
	movie->csvLine = NULL;
	return 0;
}

/*testing sorting - SUCCESS!
void printArray(char *A[], int size)
{
    int i;
    for (i=0; i < size; i++)
//        printf("%d ", A[i]);
        printf("%s, ", A[i]);
    printf("\n");
}
*/


/* arg: head of LL. number of columns, column headers
* ret: 0 if completed
* prints the movmies as a csv to stdout
*/
int printMoviesAsCsv(movieLine* head, int numColumns, char** columnNames){
	int i;
	for (i = 0; i < numColumns; ++i)
	{
		printf("%s", columnNames[i]);
		if(i < numColumns - 1){
			printf(",");
		} else {
			printf("\r\n");
		}
	}
	movieLine* curr = head;
	while(curr != NULL){
		if(curr->next != NULL){
			if(curr->csvLine != NULL){
				printf("%s\n", curr->csvLine);
			}
		} else {
			if(curr->csvLine != NULL){
				printf("%s", curr->csvLine);
			}
		}
		curr = curr->next;
	}
	return 0;
}

// arg: movieline pointer
// ret: 0 if it is an empty node, 1 if it has any data
int hasNoFields(movieLine* movie){
	if(movie->color == NULL &&
		movie->director_name == NULL &&
		movie->num_critic_for_reviews == -1 &&
		movie->duration == -1 &&
		movie->director_facebook_likes == -1 &&
		movie->actor_3_facebook_likes == -1 &&
		movie->actor_2_name == NULL &&
		movie->actor_1_facebook_likes == -1 &&
		movie->gross == -1 &&
		movie->genres == NULL &&
		movie->actor_1_name == NULL &&
		movie->movie_title == NULL &&
		movie->num_voted_users == -1 &&
		movie->cast_total_facebook_likes == -1 &&
		movie->actor_3_name == NULL &&
		movie->facenumber_in_poster == -1 &&
		movie->plot_keywords == NULL &&
		movie->movie_imdb_link == NULL &&
		movie->num_user_for_reviews == -1 &&
		movie->language == NULL &&
		movie->country == NULL &&
		movie->content_rating == NULL &&
		movie->budget == -1 &&
		movie->title_year == -1 &&
		movie->actor_2_facebook_likes == -1 &&
		movie->imdb_score == -1 &&
		movie->aspect_ratio == -1 &&
		movie->movie_facebook_likes == -1 &&
		movie->next == NULL &&
		movie->csvLine == NULL){
		return 0;
	} else{
		return 1;
	}

}

/* arg: column number, array of column headers, movie line pointer, string to add at that column
* ret 0 if completed
* adds data to the movie based on what kind of column it corresponds to
*/
int addFieldToMovie(int columnNumber, char** columnNames, movieLine* movie, char* value){
	// special case for csvline denoted by column number -1
	if(columnNumber < 0){
		movie->csvLine = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->csvLine, value);
		if(DEBUG){ printf("Line added %s\n", movie->csvLine);}
		return 0;
	}

	char* columnName = columnNames[columnNumber];
	if(DEBUG){ printf("value %s  at column %d\n", value, columnNumber);}
	if (strcmp(columnName, "color") == 0){
		movie->color = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->color, value);
		if (DEBUG) { printf("%s %d %s\n", "color", columnNumber, value); }
	}
	else if (strcmp(columnName, "director_name") == 0){
		movie->director_name = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->director_name, value);
		if (DEBUG) { printf("%s %s\n", "director_name", value); }
	}
	else if (strcmp(columnName, "num_critic_for_reviews") == 0){
		if(value[0] != '\0'){
			movie->num_critic_for_reviews = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "num_critic_for_reviews", atoi(value)); }
	}
	else if (strcmp(columnName, "duration") == 0){
		if(value[0] != '\0'){
			movie->duration = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "duration", atoi(value)); }
	}
	else if (strcmp(columnName, "director_facebook_likes") == 0){
		if(value[0] != '\0'){
			movie->director_facebook_likes = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "director_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_3_facebook_likes") == 0){
		if(value[0] != '\0'){
			movie->actor_3_facebook_likes = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "actor_3_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_2_name") == 0){
		movie->actor_2_name = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->actor_2_name, value);
		if (DEBUG) { printf("%s %s\n", "actor_2_name", value); }
	}
	else if (strcmp(columnName, "actor_1_facebook_likes") == 0){
		if(value[0] != '\0'){
			movie->actor_1_facebook_likes = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "actor_1_facebook_likes", atoi(value)); }

	}
	else if (strcmp(columnName, "gross") == 0){
		if(value[0] != '\0'){
			movie->gross = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "gross", atoi(value)); }
	}
	else if (strcmp(columnName, "genres") == 0){
		movie->genres = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->genres, value);
		if (DEBUG) { printf("%s %s\n", "genres", value); }
	}
	else if (strcmp(columnName, "actor_1_name") == 0){
		movie->actor_1_name = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->actor_1_name, value);
		if (DEBUG) { printf("%s %s\n", "actor_1_name", value); }
	}
	else if (strcmp(columnName, "movie_title") == 0){
		movie->movie_title = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->movie_title, value);
		if (DEBUG) { printf("%s %s\n", "movie_title", value); }
	}
	else if (strcmp(columnName, "num_voted_users") == 0){
		if(value[0] != '\0'){
			movie->num_voted_users = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "num_voted_users", atoi(value)); }
	}
	else if (strcmp(columnName, "cast_total_facebook_likes") == 0){
		if(value[0] != '\0'){
			movie->cast_total_facebook_likes = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "cast_total_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_3_name") == 0){
		movie->actor_3_name = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->actor_3_name, value);
		if (DEBUG) { printf("%s %s\n", "actor_3_name", value); }
	}
	else if (strcmp(columnName, "facenumber_in_poster") == 0){
		if(value[0] != '\0'){
			movie->facenumber_in_poster = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "facenumber_in_poster", atoi(value)); }
	}
	else if (strcmp(columnName, "plot_keywords") == 0){
		movie->plot_keywords = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->plot_keywords, value);
		if (DEBUG) { printf("%s %s\n", "plot_keywords", value); }
	}
	else if (strcmp(columnName, "movie_imdb_link") == 0){
		movie->movie_imdb_link = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->movie_imdb_link, value);
		if (DEBUG) { printf("%s %s\n", "movie_imdb_link", value); }
	}
	else if (strcmp(columnName, "num_user_for_reviews") == 0){
		if(value[0] != '\0'){
			movie->num_user_for_reviews = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "num_user_for_reviews", atoi(value)); }
	}
	else if (strcmp(columnName, "language") == 0){
		movie->language = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->language, value);
		if (DEBUG) { printf("%s %s\n", "language", value); }
	}
	else if (strcmp(columnName, "country") == 0){
		movie->country = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->country, value);
		if (DEBUG) { printf("%s %s\n", "country", value); }
	}
	else if (strcmp(columnName, "content_rating") == 0){
		movie->content_rating = malloc(sizeof(char) * (strlen(value) + 1));
		strcpy(movie->content_rating, value);
		if (DEBUG) { printf("%s %s\n", "content_rating", value); }
	}
	else if (strcmp(columnName, "budget") == 0){
		if(value[0] != '\0'){
			movie->budget = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "budget", atoi(value)); }
	}
	else if (strcmp(columnName, "title_year") == 0){
		if(value[0] != '\0'){
			movie->title_year = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "title_year", atoi(value)); }
	}
	else if (strcmp(columnName, "actor_2_facebook_likes") == 0){
		if(value[0] != '\0'){
			movie->actor_2_facebook_likes = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "actor_2_facebook_likes", atoi(value)); }
	}
	else if (strcmp(columnName, "imdb_score") == 0){
		if(value[0] != '\0'){
			movie->imdb_score = atof(value);
		}
		if (DEBUG) { printf("%s %f\n", "imdb_score", atof(value)); }
	}
	else if (strcmp(columnName, "aspect_ratio") == 0){
		if(value[0] != '\0'){
			movie->aspect_ratio = atof(value);
		}
		if (DEBUG) { printf("%s %f\n", "aspect_ratio", atof(value)); }
	}
	else if (strcmp(columnName, "movie_facebook_likes") == 0){
		if(value[0] != '\0'){
			movie->movie_facebook_likes = atoi(value);
		}
		if (DEBUG) { printf("%s %d\n", "movie_facebook_likes", atoi(value)); }
	}
	return 0;
}

int main(int argc, char *argv[]){
    //check if there are correct # of argument inputs
    if (argc == 3){
        //check if command is correct
        if (strcmp(argv[1], "-c") == 0){
            //check if column name is valid
//            if (){        - loop here to go thru and check all types
//
//            }else{
//
//            }

            /*
            //testing sorting with small inputs - int
//            int arr[] = {100, 12, 11, 13, 5, 6, 7};
            char *arr[] = {"James Cameron", "Gore Verbinski", "Sam Mendes", "Christopher Nolan", "Doug Walker", "Andrew Stanton", "Sam Raimi"};
            int arr_size = sizeof(arr)/sizeof(arr[0]);

            printf("Given array is \n");
            printArray(arr, arr_size);

//            numMergeSort(arr, 0, arr_size - 1);
            strMergeSort(arr, 0, arr_size - 1);

            printf("\nSorted array is \n");
            printArray(arr, arr_size);
            //
            */

            char columnsLine[2000];
            char buffer;
            int lineCounter = 0;
            if(DEBUG) { printf("Reading in first line\n"); }
            read(0, &buffer, 1);
            while(buffer != '\n'){
                if(DEBUG){printf("%c", buffer);}
                columnsLine[lineCounter] = buffer;
                lineCounter++;
                read(0, &buffer, 1);
            }
            if(DEBUG){ printf("\n"); }
            columnsLine[lineCounter] = '\0';
            if(DEBUG){
                if(columnsLine[lineCounter - 1] == '\n' || columnsLine[lineCounter] == '\n'){
                    printf("misplaced newline at the end of the columns string\n");
                }
            }

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
                    if(DEBUG){ printf("column name %s inserted into column names array\n", columnNames[currColumnNum]); }
                    currColumnNum++;
                    currStringIndex = 0;
                    continue;
                }
                columnNames[currColumnNum][currStringIndex] = columnsLine[i];
                currStringIndex++;
            }

            columnNames[currColumnNum][currStringIndex - 1] = '\0';


            if(DEBUG){
                printf("Last columnName is: %s\n", columnNames[numColumns - 1]);
                if(columnNames[numColumns - 1][strlen(columnNames[numColumns - 1])] == '\n'){
                    printf("misplaced newline in the last character of last string\n");
                }
            }
            // print out column names for testing
            if(DEBUG){
                for(i = 0; i < numColumns; i++){
                    printf("column: %s at number %d\n", columnNames[i], i);
                    if(columnNames[i][strlen(columnNames[i] - 1)] == '\n'){
                            printf("misplaced newline in the last character of last string\n");
                    }
                }
            }


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
            char individualMovieLine[500];
            int movieLineCharacterIndex = 0;
            if(DEBUG2){ printf("Line %d\n", __LINE__);}
            while(read(0, &buffer, 1) != 0){
                if(buffer == '"'){
                    quotationMark = !quotationMark;
                    individualMovieLine[movieLineCharacterIndex] = buffer;
                    movieLineCharacterIndex++;
                    continue;
                }
                if (buffer == ',' && !quotationMark)
                {
                    individualMovieLine[movieLineCharacterIndex] = buffer;
                    movieLineCharacterIndex++;
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
                    individualMovieLine[movieLineCharacterIndex] = '\0';
                    movieLineCharacterIndex = 0;
                    currCellText[currCellTextIndex - 1] = '\0';
                    currCellTextIndex = 0;
                    addFieldToMovie(cellNumber, columnNames, currMovie, currCellText);
                    cellNumber = 0;
                    currCellText[0] = '\0';
                    if(DEBUG2){printf("%s\n", individualMovieLine);}

                    movieLine* newMovie = malloc(sizeof(movieLine));
                    initMovieLine(newMovie);
                    addFieldToMovie(-1, columnNames, currMovie, individualMovieLine);
                    //strcpy(currMovie->csvLine, individualMovieLine);
                    moviesLL->rear = newMovie;
                    currMovie->next = newMovie;
                    currMovie = newMovie;
                    continue;
                }

                currCellText[currCellTextIndex] = buffer;
                currCellTextIndex++;
                individualMovieLine[movieLineCharacterIndex] = buffer;
                movieLineCharacterIndex++;

            }


            movieLine* currIter = moviesLL->head;
            while(currIter->next != NULL){
            	if(hasNoFields(currIter->next) == 0){
            		moviesLL->rear = currIter;
            		free(currIter->next);
            		currIter->next = NULL;
            		break;
            	}
            	currIter = currIter->next;
            }

            // deal with the last character
            //currCellText[currCellTextIndex] = '\0';
            //addFieldToMovie(cellNumber, columnNames, currMovie, currCellText);
            //strcpy(currMovie->csvLine, individualMovieLine);

            //Before sorting!
            //printf("\n\n\n\n\nBefore Sorting!\n\n\n\n\n");
            //printMoviesAsCsv(moviesLL->head, numColumns, columnNames);

            int counter = 0;

            if ((strcmp(argv[2], "color") == 0) || (strcmp(argv[2], "director_name") == 0) || (strcmp(argv[2], "actor_2_name") == 0) || (strcmp(argv[2], "genres") == 0) || (strcmp(argv[2], "actor_1_name") == 0) || (strcmp(argv[2], "movie_title") == 0) || (strcmp(argv[2], "actor_3_name") == 0) || (strcmp(argv[2], "plot_keywords") == 0) || (strcmp(argv[2], "movie_imdb_link") == 0) || (strcmp(argv[2], "language") == 0) || (strcmp(argv[2], "country") == 0) || (strcmp(argv[2], "content_rating") == 0))
            {
                //all char * cases
                //printf("COLUMN NAME type is String!\n\n");
                for (i = 0; i < numColumns; i++)
                {
                    //printf("%s\n", columnNames[i]);
                    if (strcmp(argv[2], columnNames[i]) == 0)   //case when there are only subsets of column names
                    {
                        counter = 1;
                        break;
                    }
                }

                if (counter == 1)   //sort only if the column name actually exists
                {
                    mergeSort(&(moviesLL->head), argv[2], NULL);
                    printMoviesAsCsv(moviesLL->head, numColumns, columnNames);
                }else
                {
                    printf("ERROR: INPUTTED COLUMN NAME DOES NOT EXIST!\n\n");
                }


            }else if ((strcmp(argv[2], "num_critic_for_reviews") == 0) || (strcmp(argv[2], "duration") == 0) || (strcmp(argv[2], "director_facebook_likes") == 0) || (strcmp(argv[2], "actor_3_facebook_likes") == 0) || (strcmp(argv[2], "actor_1_facebook_likes") == 0) || (strcmp(argv[2], "gross") == 0) || (strcmp(argv[2], "num_voted_users") == 0) || (strcmp(argv[2], "cast_total_facebook_likes") == 0) || (strcmp(argv[2], "facenumber_in_poster") == 0) || (strcmp(argv[2], "num_user_for_reviews") == 0) || (strcmp(argv[2], "budget") == 0) || (strcmp(argv[2], "title_year") == 0) || (strcmp(argv[2], "actor_2_facebook_likes") == 0) || (strcmp(argv[2], "imdb_score") == 0) || (strcmp(argv[2], "aspect_ratio") == 0) || (strcmp(argv[2], "movie_facebook_likes") == 0))
            {
                //all int + double cases
                //printf("COLUMN NAME type is int/double!\n\n");
                for (i = 0; i < numColumns; i++)
                {
                    //printf("%s\n", columnNames[i]);
                    if (strcmp(argv[2], columnNames[i]) == 0)   //case when there are only subsets of column names
                    {
                        counter = 1;
                        break;
                    }
                }

                if (counter == 1)   //sort only if the column name actually exists
                {
                    mergeSort(&(moviesLL->head), NULL, argv[2]);
                    printMoviesAsCsv(moviesLL->head, numColumns, columnNames);
                }else
                {
                    printf("ERROR: INPUTTED COLUMN NAME DOES NOT EXIST!\n\n");
                }
            }else
            {
                printf("ERROR: INVALID COLUMN NAME!\n\n");
            }

            //After sorting!
            //printf("\n\n\n\n\nAfter Sorting!\n\n\n\n\n");

            free(columnNames);
            //printf("SUCCESS!\n\n");
        }else{
            printf("Usage: simpleCSVsorter -c <column name>\n\n");
        }
    }else {
//        fprintf(stderr, "\nERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS\n");   - same error statement but with stderr
        printf("ERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS!\n\n");
    }
    return 0;
}


