#include <stdio.h>

int Clear_Arr(int *arr, int *arrclr, int len)
{
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        if(*(arr + i) != 0)
        {
            *(arrclr + j) = *(arr + i);
            j++;
        }
    }
    return j;
}