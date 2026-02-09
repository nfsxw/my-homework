#include <stdio.h>

void Square(int *arr, int *arrsq, int len)
{
    for(int i = 0; i < len; i++)
    {
        *(arrsq + i) = (*(arr + i)) * (*(arr + i));
    }
}