#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleCSVsorter.h"

//this function removes the leading and trailing spaces of string type inputs
char *trim(char *str)
{
    int index = 0, i = 0, counter = 0;

    while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t')
    {
        index++;
    }

    while (str[index + i] != '\0')
    {
        str[i] = str[index + i];
        i++;
    }
    str[i] = '\0';  //leading spaces removed

    i = 0, index = -1;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            index = i;
            counter++;
        }else
        {
            counter = 0;
        }
        i++;
    }

    //printf("\nBefore: %s.\n", str);
    //printf("\nCounter: %d.\n", counter);
    if (counter >= 1)
    {
        str[index - counter + 1] = '\0';  //remove trailing spaces
    }
    //printf("\nAfter: %s.\n", str);
//    free(str);
    return str;
}

struct movieLine* merge(struct movieLine* x, struct movieLine* y, char *strInput, char *numInput)   //parameters are column names - Strings
{
    struct movieLine* result = NULL;

    //recursive - base case
    if (x == NULL)
    {
        return y;
    }else if (y == NULL)
    {
        return x;
    }

    //check if sorting string types or number types
    if (strInput == NULL)       //checking all int/double column name types
    {

        /* C cannot do this
        if (x->numInput <= y->numInput)
        {
            result = x;
            result->next = merge(x->next, y, strInput, numInput);
        }else
        {
            result = y;
            result->next = merge(x, y->next, strInput, numInput);
        }
        */
        if (strcmp(numInput, "num_critic_for_reviews") == 0)
        {
            if (x->num_critic_for_reviews <= y->num_critic_for_reviews)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "duration") == 0)
        {
            if (x->duration <= y->duration)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "director_facebook_likes") == 0)
        {
            if (x->director_facebook_likes <= y->director_facebook_likes)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "actor_3_facebook_likes") == 0)
        {
            if (x->actor_3_facebook_likes <= y->actor_3_facebook_likes)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "actor_1_facebook_likes") == 0)
        {
            if (x->actor_1_facebook_likes <= y->actor_1_facebook_likes)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "gross") == 0)
        {
            if (x->gross <= y->gross)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "num_voted_users") == 0)
        {
            if (x->num_voted_users <= y->num_voted_users)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "cast_total_facebook_likes") == 0)
        {
            if (x->cast_total_facebook_likes <= y->cast_total_facebook_likes)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "facenumber_in_poster") == 0)
        {
            if (x->facenumber_in_poster <= y->facenumber_in_poster)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "num_user_for_reviews") == 0)
        {
            if (x->num_user_for_reviews <= y->num_user_for_reviews)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "budget") == 0)
        {
            if (x->budget <= y->budget)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "title_year") == 0)
        {
            if (x->title_year <= y->title_year)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "actor_2_facebook_likes") == 0)
        {
            if (x->actor_2_facebook_likes <= y->actor_2_facebook_likes)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "imdb_score") == 0)
        {
            if (x->imdb_score <= y->imdb_score)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "aspect_ratio") == 0)
        {
            if (x->aspect_ratio <= y->aspect_ratio)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(numInput, "movie_facebook_likes") == 0)
        {
            if (x->movie_facebook_likes <= y->movie_facebook_likes)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else
        {
            printf("HOW DID U GET HERE? - not possible (ROUND 1)\n\n");
        }


    }else if (numInput == NULL)     //checking all string column name types
    {
        /* Does not work in  C
        if (strcmp(x->strInput, y->strInput) <= 0)
        {
            result = x;
            result->next = merge(x->next, y, strInput, numInput);
        }else
        {
            result = y;
            result->next = merge(x, y->next, strInput, numInput);
        }
        */

        if (strcmp(strInput, "color") == 0)
        {
            if (strcmp(trim(x->color), trim(y->color)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "director_name") == 0)
        {
            if (strcmp(trim(x->director_name), trim(y->director_name)) <= 0)
            {
                //printf("\n x bef: %s, y bef: %s.\t x aft: %s, y aft: %s.\t result: Smaller\n", x->director_name, y->director_name, trim(x->director_name), trim(y->director_name));
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                //printf("\n x bef: %s, y bef: %s.\t x aft: %s, y aft: %s.\t result: Bigger\n", x->director_name, y->director_name, trim(x->director_name), trim(y->director_name));
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "actor_2_name") == 0)
        {
            if (strcmp(trim(x->actor_2_name), trim(y->actor_2_name)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "genres") == 0)
        {
            if (strcmp(trim(x->genres), trim(y->genres)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "actor_1_name") == 0)
        {
            if (strcmp(trim(x->actor_1_name), trim(y->actor_1_name)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "movie_title") == 0)
        {
            if (strcmp(trim(x->movie_title), trim(y->movie_title)) <= 0)
            {
                //printf("\n x bef: %s, y bef: %s.\t x aft: %s, y aft: %s.\t result: Smaller\n", x->movie_title, y->movie_title, trim(x->movie_title), trim(y->movie_title));
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                //printf("\n x bef: %s, y bef: %s.\t x aft: %s, y aft: %s.\t result: Bigger\n", x->movie_title, y->movie_title, trim(x->movie_title), trim(y->movie_title));
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "actor_3_name") == 0)
        {
            if (strcmp(trim(x->actor_3_name), trim(y->actor_3_name)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "plot_keywords") == 0)
        {
            if (strcmp(trim(x->plot_keywords), trim(y->plot_keywords)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "movie_imdb_link") == 0)
        {
            if (strcmp(trim(x->movie_imdb_link), trim(y->movie_imdb_link)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "language") == 0)
        {
            if (strcmp(trim(x->language), trim(y->language)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "country") == 0)
        {
            if (strcmp(trim(x->country), trim(y->country)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else if (strcmp(strInput, "content_rating") == 0)
        {
            if (strcmp(trim(x->content_rating), trim(y->content_rating)) <= 0)
            {
                result = x;
                result->next = merge(x->next, y, strInput, numInput);
            }else
            {
                result = y;
                result->next = merge(x, y->next, strInput, numInput);
            }
        }else
        {
            printf("HOW DID U GET HERE? - not possible (ROUND 2)\n\n");
        }


    }else
    {
        printf("TEMPORARY ERROR FLAG");
    }

    return result;
};

void split(struct movieLine* source, struct movieLine** ptrFront, struct movieLine** ptrBack)
{
    struct movieLine* fast;
    struct movieLine* slow;

    slow = source;
    fast = source->next;

    while(fast != NULL)     //move fast once and check if its not NULL
    {
        fast = fast->next;

        if (fast != NULL)   //if fast != NULL then move both slow and fast once
        {
            slow = slow->next;
            fast = fast->next;
        }

    }

    *ptrFront = source;     // head/first node
    *ptrBack = slow->next;  // starting node for second-half
    slow->next = NULL;      //end partitioning
}

//sorts the csv linked list - recursive fn
void mergeSort(struct movieLine** ptrHead, char *strInput, char *numInput)
{
    struct movieLine* head = *ptrHead;
    struct movieLine* x;
    struct movieLine* y;

    if (head == NULL || head->next == NULL)     //base case for recursive call
    {
        return;
    }

    split(head, &x, &y);

    mergeSort(&x, strInput, numInput);      //recursive call on mergeSort for each parts
    mergeSort(&y, strInput, numInput);

    *ptrHead = merge(x, y, strInput, numInput);
}

/*

//For sorting numeric types
//m = middleIndex
void numMerge(int arr[], int l, int m, int r)
{
    //initialize few variables
    int i, j, k;
    int temp1Size = m - l + 1, temp2Size = r - m;
    int temp1Arr[temp1Size], temp2Arr[temp2Size];   //create 2 temp arrays to store array elements

    //Store prev array elements into newly created
    for (i = 0; i < temp1Size; i++)
    {
        temp1Arr[i] = arr[l + i];
    }

    for (j = 0; j < temp2Size; j++)
    {
        temp2Arr[j] = arr[m + 1 + j];
    }

    //reset & set index positions
    i = 0, j = 0, k = l;
    //merge 2 arrays back to 1 array
    while (i < temp1Size && j < temp2Size)
    {
        if (temp1Arr[i] <= temp2Arr[j])
        {
            arr[k] = temp1Arr[i];
            i++;
        }
        else
        {
            arr[k] = temp2Arr[j];
            j++;
        }
        k++;
    }

    //add leftover elements into array
    while (i < temp1Size)
    {
        arr[k] = temp1Arr[i];
        i++;
        k++;
    }
    while (j < temp2Size)
    {
        arr[k] = temp2Arr[j];
        j++;
        k++;
    }
}

//l = leftIndex, r = rightIndex
//recursive call
void numMergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r)/2;  //find mid index

        numMergeSort(arr, l, m);
        numMergeSort(arr, m+1, r);

        numMerge(arr, l, m, r);
    }
}



//For soring String types
void strMerge(char *arr[], int l, int m, int r)
{
    //initialize few variables
    int i, j, k;
    int temp1Size = m - l + 1, temp2Size = r - m;
    char *temp1Arr[temp1Size], *temp2Arr[temp2Size];   //create 2 temp arrays to store array elements

    //Store prev array elements into newly created
    for (i = 0; i < temp1Size; i++)
    {
        temp1Arr[i] = arr[l + i];
    }

    for (j = 0; j < temp2Size; j++)
    {
        temp2Arr[j] = arr[m + 1 + j];
    }

    //reset & set index positions
    i = 0, j = 0, k = l;
    //merge 2 arrays back to 1 array
    while (i < temp1Size && j < temp2Size)
    {
        if (strcmp(temp1Arr[i], temp2Arr[j]) <= 0)
        {
            arr[k] = temp1Arr[i];
            i++;
        }
        else
        {
            arr[k] = temp2Arr[j];
            j++;
        }
        k++;
    }

    //add leftover elements into array
    while (i < temp1Size)
    {
        arr[k] = temp1Arr[i];
        i++;
        k++;
    }
    while (j < temp2Size)
    {
        arr[k] = temp2Arr[j];
        j++;
        k++;
    }
}

void strMergeSort(char *arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r)/2;  //find mid index

        strMergeSort(arr, l, m);
        strMergeSort(arr, m+1, r);

        strMerge(arr, l, m, r);
    }
}

*/
