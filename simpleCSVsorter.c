#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "simpleCSVsorter.h"

//testing sorting - SUCCESS!
void printArray(char *A[], int size)
{
    int i;
    for (i=0; i < size; i++)
//        printf("%d ", A[i]);
        printf("%s, ", A[i]);
    printf("\n");
}

int
main(int argc, char *argv[]){
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

            if (strcmp(argv[2], "color") == 0) || (strcmp(argv[2], "director_name") == 0) || (strcmp(argv[2], "actor_2_name") == 0) || (strcmp(argv[2], "genres") == 0) || (strcmp(argv[2], "actor_1_name") == 0) || (strcmp(argv[2], "movie_title") == 0) || (strcmp(argv[2], "actor_3_name") == 0) || (strcmp(argv[2], "plot_keywords") == 0) || (strcmp(argv[2], "movie_imdb_link") == 0) || (strcmp(argv[2], "language") == 0) || (strcmp(argv[2], "country") == 0) || (strcmp(argv[2], "content_rating") == 0)
            {
                //all char * cases
                printf("COLUMN NAME type is String!\n\n");
                mergeSort(&head, *argv[2], NULL);

            }else if (strcmp(argv[2], "num_critic_for_reviews") == 0) || (strcmp(argv[2], "duration") == 0) || (strcmp(argv[2], "director_facebook_likes") == 0) || (strcmp(argv[2], "actor_3_facebook_likes") == 0) || (strcmp(argv[2], "actor_1_facebook_likes") == 0) || (strcmp(argv[2], "gross") == 0) || (strcmp(argv[2], "num_voted_users") == 0) || (strcmp(argv[2], "cast_total_facebook_likes") == 0) || (strcmp(argv[2], "facenumber_in_poster") == 0) || (strcmp(argv[2], "num_user_for_reviews") == 0) || (strcmp(argv[2], "budget") == 0) || (strcmp(argv[2], "title_year") == 0) || (strcmp(argv[2], "actor_2_facebook_likes") == 0) || (strcmp(argv[2], "imdb_score") == 0) || (strcmp(argv[2], "aspect_ratio") == 0) || (strcmp(argv[2], "movie_facebook_likes") == 0)
            {
                //all int + double cases
                printf("COLUMN NAME type is int/double!\n\n");
                mergeSort(&head, NULL, *argv[2]);
            }else
            {
                printf("INVALID COLUMN NAME!\n\n");
            }

            //printf("SUCCESS!\n\n");
        }else{
            printf("Usage: simpleCSVsorter -c <column name>\n\n");
        }
    }else {
//        fprintf(stderr, "\nERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS\n");   - same error statement but with stderr
        printf("\nERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS\n");
    }
    return 0;
}


