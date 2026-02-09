#include <stdio.h>
#include <stdlib.h>
#include "Arr_Input_Output.h"
#include "Malloc_Check.h"
#include "Clear_arr.h"

int main()
{
    int N = LenChoice();

    int *arr = malloc(sizeof(int) * N);
    Malloc_Check(arr);
    int *arrclr = malloc(sizeof(int) * N);
    Malloc_Check(arrclr);

    InputArray(arr, N);
    int len = Clear_Arr(arr, arrclr, N);
    OutputArray(arrclr, len);

    free(arr);
    free(arrclr);
    arr = NULL;
    arrclr = NULL;
    printf("\n");
}