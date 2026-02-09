#include <stdio.h>
#define MAX_SIZE 1000
#include "InputArray.h"
#include "SelectionSortAsc.h"
#include "SelectionSortDesc.h"
#include "PrintArray.h"
#include <time.h>
#include <stdlib.h>

int FillRandom(int [], int);
int main()
{
    int arr[MAX_SIZE], len = FillRandom(arr, MAX_SIZE);
    clock_t start;
    clock_t end;
    if (len != 0)
    {
        char c;
        printf("Choose an order of sort: Ascending(a) / Descending(d):\n");
        scanf(" %c", &c);
        while(c != 'a' && c != 'd')
        {
            scanf("%c", &c);
        }
        if(c == 'a')
        {
            start = clock();
            for(int i = 0; i < 10000; i++) SelectionSortAsc(arr, len);
            end = clock();
        }
        if (c == 'd')
        {
            start = clock();
            for(int i = 0; i < 10000; i++) SelectionSortDesc(arr, len);
            end = clock();
        }
        double time = (double)(end - start) / (10000 * CLOCKS_PER_SEC);
        PrintArray(arr, len);
        printf("Time: %.12f", time);
    }
    return 0;
}

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