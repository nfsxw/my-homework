#include <stdio.h>
#define MAX_SIZE 1000
#include "InputArray.h"
#include "RemoveDuplicates.h"

int main()
{
    int arr[MAX_SIZE];  

    printf("Enter array:\n");
    int len1 = InputArray(arr);

    int len2 = RemoveDuplicates(arr, len1);

    if (len1 == 0)
    {
        printf("Empty array.\n");
    }
    else
    {
        printf("Array without repetitions:\n");
        for (int i = 0; i < len2; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
