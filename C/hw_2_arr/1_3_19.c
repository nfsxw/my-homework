#include <stdio.h>
#define MAX_SIZE 1000

int InputArray(int[]);
int RemoveDuplicates(int[], int);
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

int InputArray(int arr[])
{
    int len = 0, num;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if((scanf("%d", &num)) == 1)
        {
            arr[i] = num;
            len++;
        }
        else
        {
            break;
        }
    }

    return len;
}

int RemoveDuplicates(int arr[], int len1)
{
    int isNew, len2 = 0;
    for (int i = 0; i < len1; i++)
    {
        isNew = 1;
        for (int j = 0; j < len2; j++)
        {
            if(arr[i] == arr[j])
            {
                isNew = 0;
                break;
            }
        }
        if(isNew)
        {
        arr[len2] = arr[i];
        len2++;
        }
    }
    return len2;
}