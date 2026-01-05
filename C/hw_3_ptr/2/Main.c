#include <stdio.h>
#include <stdlib.h>
#include "Arr_Input_Output.h"
#include "Malloc_Check.h"
#include "Attitude.h"

int main()
{
    int N = LenChoice();
    int *arr = malloc(sizeof(int) * N);
    Malloc_Check(arr);

    InputArray(arr, N);

    int min, max;
    Min_Max(arr, N, &min, &max);

    free(arr);
    arr = NULL;    
    printf("Min: %d. Max: %d.\n", min, max);
}