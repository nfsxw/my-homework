#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

int InputChoice(int arr[])
{
    char c;
    int len;
    printf("Generate random sequence (a) or Enter your sequence (b)? \n");
    scanf(" %c", &c);
    while (c != 'a' && c != 'b')
    {
        printf("Enter a or b: \n");
        scanf(" %c", &c);
    }
    if (c == 'a')
    {
        len = FillRandom(arr, MAX_SIZE);
        printf("Your sequence:\n");
        PrintArray(arr, len);
    }
    else if (c == 'b')
    {
        len = InputArray(arr);
    }
    return len;
}