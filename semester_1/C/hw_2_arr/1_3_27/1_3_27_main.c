#include <stdio.h>
#define MAX_SIZE 1000
#include "InputCheck.h"
#include "Init.h"
#include "PascalRow.h"
#include "PrintArray.h"

int main()
{
    int n = InputCheck();
    int arr[n + 1];
    Init (arr, n);
    PascalRow(arr, n);
    PrintArray(arr, n);
    printf("\n");
    return 0;
}
