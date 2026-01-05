#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

void SortingAsc(int arr[], int len)
{
    if (len <= 1) return;
    int left = 0, right = len - 1;
    int piv = arr[rand() % len];
    
    while (left <= right)
    {
        while (left < len && arr[left] < piv) left++;
        while (right >= 0 && arr[right] > piv) right--;

        if(left <= right)
        {
            Swap(&arr[left], &arr[right]);
            left++, right--;        
        }
    }

    int left_len = right + 1;
    int right_len = len - left;

    if(left_len > 1) SortingAsc(arr, left_len);
    if(right_len > 1) SortingAsc(arr + left, right_len);
}