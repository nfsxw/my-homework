#include <stdlib.h>
#include <string.h>
#include "Sort_Res.h"

int Q_sort()
{
    char c = Input_check(ASC_DESC_MSG);
    switch (c)
    {
        case 'a':
            strcpy(sort_type, "Quick_asc");
            if(Time_mes(Quick_sort_asc)) return 1;
            break;
        case 'b':
            strcpy(sort_type, "Quick_desc");
            if(Time_mes(Quick_sort_desc)) return 1;
            break;
    }
    return 0;
}

void Quick_sort_asc(int *arr, int len)
{
    if (len <= 1) return;
    int left = 0, right = len - 1;
    int piv = *(arr + (rand() % len));
    
    while (left <= right)
    {
        while (left <= right && *(arr + left) < piv) left++;
        while (left <= right && *(arr + right) > piv) right--;

        if(left <= right)
        {
            Swap((arr + left), (arr + right));
            left++, right--;        
        }
    }

    int left_len = right + 1;
    int right_len = len - left_len;

    if(left_len > 1 && right_len > 1 && len > 20000)
    {
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                Quick_sort_asc(arr, left_len);
            }
            #pragma omp section
            {
                Quick_sort_asc(arr + left_len, right_len);
            }
        }
    }
    else
    {
        if(left_len > 1) Quick_sort_asc(arr, left_len);
        if(right_len > 1) Quick_sort_asc(arr + left_len, right_len);
    }
}

void Quick_sort_desc(int *arr, int len)
{
    if (len <= 1) return;
    int left = 0, right = len - 1;
    int piv = *(arr + (rand() % len));
    
    while (left <= right)
    {
        while (left <= right && *(arr + left) > piv) left++;
        while (left <= right && *(arr + right) < piv) right--;

        if(left <= right)
        {
            Swap((arr + left), (arr + right));
            left++, right--;        
        }
    }

    
    int left_len = right + 1;
    int right_len = len - left_len;

    if(left_len > 1 && right_len > 1 && len > 20000)
    {
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                Quick_sort_desc(arr, left_len);
            }
            #pragma omp section
            {
                Quick_sort_desc(arr + left_len, right_len);
            }
        }

    }
    else
    {
        if(left_len > 1) Quick_sort_desc(arr, left_len);
        if(right_len > 1) Quick_sort_desc(arr + left_len, right_len);
    }
    
}

void Swap(int *a, int *b)
{
    if(a == NULL || b == NULL) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}