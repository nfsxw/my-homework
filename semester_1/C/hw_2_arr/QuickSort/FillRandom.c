#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

int FillRandom(int arr[], int size)
{   
    int min, max, len;
    printf("Enter lower limit of generation: \n");
    scanf("%d", &min);
    printf("Enter higher limit of generation: \n");
    scanf("%d", &max);

    while(min > max)
    {
        printf("min > max.\n");
        printf("Enter lower limit of generation: \n");
        scanf("%d", &min);
        printf("Enter higher limit of generation: \n");
        scanf("%d", &max);
        
    }
    printf("Enter number of digits in sequence: \n");
    scanf("%d", &len);

    while (len < 0 || len > size)
    {
        printf("Number of digits must be less than %d. \n", size);
        scanf("%d", &len);
    }
    
    for (int i = 0; i < len; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
    return len;
}