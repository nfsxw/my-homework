#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include "Sort_Res.h"

int M_sort()
{
    char c = Input_check(ASC_DESC_MSG);
    switch (c)
    {
        case 'a':
            strcpy(sort_type, "Merge_asc");
            if(Time_mes(Merge_sort_adapter_asc)) return 1;
            break;
        case 'b':
            strcpy(sort_type, "Merge_desc");
            if(Time_mes(Merge_sort_adapter_desc)) return 1;
            break;
    }
    return 0;
}

void Merge_sort_adapter_asc(int *arr, int len)
{
    Merge_sort(arr, 0, len - 1, Merge_asc);
}

void Merge_sort_adapter_desc(int *arr, int len)
{
    Merge_sort(arr, 0, len - 1, Merge_desc);
}

void Merge_sort(int *arr, int l, int r, void (*func)(int*, int, int, int))
{
    if(l < r)
    {
        int m = l + (r - l)/2;
        int len = r - l + 1;
        if(len > 20000)
        {
            #pragma omp parallel sections
            {
                #pragma omp section
                {
                    Merge_sort(arr, l, m, func);                          
                }
                #pragma omp section
                {
                    Merge_sort(arr, m + 1, r, func);
                }
            }
        }
        else
        {
            Merge_sort(arr, l, m, func);
            Merge_sort(arr, m + 1, r, func);
        }
        func(arr, l , m , r);
    }
}

void Merge_asc(int *arr, int l, int m, int r)
{
    int left_len = m - l + 1, right_len = r - m, *left = NULL, *right = NULL;
    
    left = malloc(left_len * sizeof(int));
    right = malloc(right_len * sizeof(int));

    memcpy(left, arr + l, left_len * sizeof(int));
    memcpy(right, arr + m + 1, right_len * sizeof(int));

    int i = 0, j = 0, k = l;
    while(i < left_len && j < right_len)
    {
        if(*(left + i) <= *(right + j)) *(arr + k++) = *(left + i++);
        else *(arr + k++) = *(right + j++);
    }
    while(i < left_len) *(arr + k++) = *(left + i++);
    while(j < right_len) *(arr + k++) = *(right + j++);

    free(left);
    free(right);
}

void Merge_desc(int *arr, int l, int m, int r)
{
    int left_len = m - l + 1, right_len = r - m, *left = NULL, *right = NULL;
    
    left = malloc(left_len * sizeof(int));
    right = malloc(right_len * sizeof(int));

    memcpy(left, arr + l, left_len * sizeof(int));
    memcpy(right, arr + m + 1, right_len * sizeof(int));

    int i = 0, j = 0, k = l;
    while(i < left_len && j < right_len)
    {
        if(*(left + i) >= *(right + j)) *(arr + k++) = *(left + i++);
        else *(arr + k++) = *(right + j++);
    }
    while(i < left_len) *(arr + k++) = *(left + i++);
    while(j < right_len) *(arr + k++) = *(right + j++);

    free(left);
    free(right);
}