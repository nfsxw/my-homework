#include <stdio.h>
#include "quicksort.h"

int InputArray(int arr[])
{
    printf("Enter the sequence: \n");
    int len = 0, num;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if((scanf("%d", &num)) == 1)
        {
            arr[i] = num;
            len++;
        }
        else
        {
            break;
        }
    }

    return len;
}