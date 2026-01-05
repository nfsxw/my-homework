#include <stdio.h>
#include <stdlib.h>
#include "Arr_Input_Output.h"
#include "Malloc_Check.h"
#include "Square.h"

int main()
{
    int N = LenChoice();

    int *arr = malloc(sizeof(int) * N);
    Malloc_Check(arr);
    int *arrsq = malloc(sizeof(int) * N);
    Malloc_Check(arrsq);

    InputArray(arr, N);
    Square(arr, arrsq, N);
    OutputArray(arrsq, N);

    free(arr);
    free(arrsq);
    arr = NULL;
    arrsq = NULL;
    printf("\n");
}