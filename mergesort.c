#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sorts the csv linked list - recursive fn
void mergeSort(struct movieLine** ptrHead, char *strInput, double numInput)
{
    struct movieLine* head = ptrHead;
    struct movieLine* x;
    struct movieLine* y;

    if (head == NULL || head->next == NULL)     //base case for recursive call
    {
        return;
    }

    split(head, &x, &y);

    mergeSort(&x, strInput, numInput);      //recursive call on mergeSort for each parts
    mergeSort(&y, strInput, numInput);

    *source = merge(x, y);
}

struct movieLine* merge(struct movieLine* x, struct movieLine* y, char *strInput, double numInput)
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
    if (strInput == NULL)
    {
        if (x->numInput <= y->numInput)
        {
            result = x;
            result->next = merge(x->next, y, strInput, numInput);
        }else
        {
            result = y;
            result->next = merge(x, y->next, strInput, numInput);
        }
    }else if (numInput == NULL)
    {
        if (strcmp(x->strInput, y->strInput) <= 0)
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
