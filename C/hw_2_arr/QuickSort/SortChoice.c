#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

float SortChoice(int arr[], int len)
{
    clock_t start, end;
    char c;
    printf("Choose Ascending sort (a) or Descending sort (b)? \n");
    scanf(" %c", &c);
    while (c != 'a' && c != 'b')
    {
        printf("Enter a or b: \n");
        scanf(" %c", &c);
    }
    if (c == 'a')
    {
        start = clock();
        for(int i = 0; i < 10000; i++)
        {
            SortingAsc(arr, len);
        }
        end = clock();
    }
    else if (c == 'b')
    {
        start = clock();
        for (int i = 0; i < 10000; i++)
        {
            SortingDesc(arr, len);
        }
        end = clock();
    }
   
    return (double)(end - start) / (10000 * CLOCKS_PER_SEC);
}