#include <stdio.h>

void Min_Max(int *arr, int len, int *min, int *max)
{
    *min = *arr;
    *max = *arr;

    for(int i = 0; i < len; i++)
    {
        if(*(arr + i) > *max)
        {
            *max = *(arr + i);
        }
        
        if(*(arr + i) < *min)
        {
            *min = *(arr + i);
        }
    }
}