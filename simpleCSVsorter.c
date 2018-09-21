#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "simpleCSVsorter.h"

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
            printf("SUCCESS!\n\n");
        }else{
            printf("Usage: simpleCSVsorter -c <column name>\n\n");
        }
    }else {
//        fprintf(stderr, "\nERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS\n");
        printf("\nERROR: ENTER IN CORRECT NUMBER OF ARGUMENTS\n");
    }
    return 0;
}
