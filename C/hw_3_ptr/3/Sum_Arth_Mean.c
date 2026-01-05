#include <stdio.h>

float Sum_Arth_Mean(int *arr, int len, int *sum)
{
    for(int i = 0; i < len; i++)
    {
        *sum += *(arr + i);
    }
    float arm = (float)*sum / len;

    return arm;
}