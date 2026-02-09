#include <stdio.h>
#include <stdlib.h>
#include "Arr_Input_Output.h"
#include "Malloc_Check.h"

int main()
{
    int N = LenChoice();
    int *arr = malloc(N*sizeof(int));
    Malloc_Check(arr);

    InputArray(arr, N);
    OutputArrayBackw(arr, N);

    free(arr);
    arr = NULL;
    printf("\n");
    return 0;
}