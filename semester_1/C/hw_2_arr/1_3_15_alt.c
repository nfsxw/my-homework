#include <stdio.h>
#define MAX_SIZE 1000

int InputArray(int[]);
int FindIntersections(int[], int[], int[], int, int);
int RemoveDuplicates(int[], int);
int main()
{
    int arr1[MAX_SIZE], arr2[MAX_SIZE], intersection[MAX_SIZE];  

    printf("Enter array 1:\n");
    int len1 = InputArray(arr1);

    printf("Enter array 2:\n");
    int len2 = InputArray(arr2);
    
    int len3 = FindIntersections(arr1, arr2, intersection, len1, len2);

    int len4 = RemoveDuplicates(intersection, len3);

    if (len4 == 0)
    {
        printf("No intersections.\n");
    }
    else
    {
        printf("Intersection of the two sets:\n");
        for (int i = 0; i < len4; i++)
        {
            printf("%d ", intersection[i]);
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

int FindIntersections(int arr1[], int arr2[], int intersection[], int len1, int len2)
{
    int len3 = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                intersection[len3] = arr1[i];
                len3++;
                break;
            }
        }
    }
    return len3;
}

int RemoveDuplicates(int intersection[], int len3)
{
    int isNew, len4 = 0;
    for (int i = 0; i < len3; i++)
    {
        isNew = 1;
        for (int j = 0; j < len4; j++)
        {
            if(intersection[i] == intersection[j])
            {
                isNew = 0;
                break;
            }
        }
        if(isNew)
        {
        intersection[len4] = intersection[i];
        len4++;
        }
    }
    return len4;
}
