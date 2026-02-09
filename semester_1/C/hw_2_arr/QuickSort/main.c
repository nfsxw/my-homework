#define MAX_SIZE 1000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

int main()
{
    srand((unsigned int)time(NULL));
    int arr[MAX_SIZE];
    int len = InputChoice(arr);
    double time = SortChoice(arr,len);
    printf("Your sorted array:\n");
    PrintArray(arr, len);
    printf("Time: %.12f\n", time);
    return 0;
}
