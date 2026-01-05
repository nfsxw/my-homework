#include <stdio.h>
#include <stdlib.h>
#include "Arr_Input_Output.h"
#include "Malloc_Check.h"
#include "Sum_Arth_Mean.h"

int main()
{
    int N = LenChoice();
    int *arr = malloc(sizeof(int) * N);
    Malloc_Check(arr);

    InputArray(arr, N);

    int sum = 0;
    float arm = Sum_Arth_Mean(arr, N, &sum);

    free(arr);
    arr = NULL;
    printf("Arithmetic mean: %.2f Sum: %d \n", arm, sum);
}