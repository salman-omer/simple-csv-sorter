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


            //testing sorting with small inputs - int
//            int arr[] = {100, 12, 11, 13, 5, 6, 7};
            char *arr[] = {"James Cameron", "Gore Verbinski", "Sam Mendes", "Christopher Nolan", "Doug Walker"};
            int arr_size = sizeof(arr)/sizeof(arr[0]);

            printf("Given array is \n");
            printArray(arr, arr_size);

//            numMergeSort(arr, 0, arr_size - 1);
            strMergeSort(arr, 0, arr_size - 1);

            printf("\nSorted array is \n");
            printArray(arr, arr_size);
            //


            printf("SUCCESS!\n\n");
        }else{
            printf("Usage: simpleCSVsorter -c <column name>\n\n");
        }
    }else {
//        fprintf(stderr, "\nERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS\n");   - same error statement but with stderr
        printf("\nERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS\n");
    }
    return 0;
}


