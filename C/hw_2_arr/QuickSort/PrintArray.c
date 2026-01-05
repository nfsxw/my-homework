#include <stdio.h>
#include "quicksort.h"

void PrintArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}