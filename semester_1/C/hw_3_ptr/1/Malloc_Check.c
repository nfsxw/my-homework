#include <stdio.h>
#include <stdlib.h>

int Malloc_Check(int *arr)
{
    if (arr == NULL)
    {
        printf ("No memory allocated\n");
        exit(1);
    }

}