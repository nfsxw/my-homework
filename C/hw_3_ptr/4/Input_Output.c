#include <stdio.h>

void InputArray(int *arr, int len)
{
    int num;
    for (int i = 0; i < len; i++)
    {
        scanf(" %d", &num);
        *(arr + i) = num;
    }
}

void OutputArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(arr + i));
    }
}

void OutputArrayBackw(int *arr, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d ", *(arr + i));
    }
}