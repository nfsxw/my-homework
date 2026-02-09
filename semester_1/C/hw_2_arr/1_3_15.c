#include <stdio.h>
#define MAX_SIZE 1000

int duplicate(int, int);
int main()
{
    //Input:
    
    int num1, num2;
    int numbers1[MAX_SIZE], len1 = 0;

    printf("Enter array 1: \n");
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if((scanf("%d", &num1)) == 1)
        {
            numbers1[i] = num1;
            len1++;
        }
        else
        {
            break;
        }
    }

    int numbers2[MAX_SIZE], len2 = 0;

    printf("Enter array 2: \n");
    for(int j = 0; j < MAX_SIZE; j++)
    {
        if((scanf("%d", &num2)) == 1)
        {
            numbers2[j] = num2;
            len2++;
        }
        else
        {
            break;
        }
    }

    //Creating an array of intersections:

    int numbers3[MAX_SIZE], len3 = 0;

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (numbers1[i] == numbers2[j])
            {
                numbers3[len3] = numbers1[i];
                len3++;
                break;
            }
        }
    }

    //Finding and removing duplicates:

    int new, len4 = 0;
    for (int i = 0; i < len3; i++)
    {
        new = 1;
        for (int j = 0; j < len4; j++)
        {
            if(duplicate (numbers3[i], numbers3[j]))
            {
                new = 0;
                break;
            }
        }
        if(new)
        {
        numbers3[len4] = numbers3[i];
        len4++;
        }
    }


    //Output:

    if (len4 == 0)
    {
        printf("No intersections. \n");
    }
    else
    {
        printf("Intersection of the two sets: \n");
        for (int i = 0; i < len4; i++)
        {
            printf("%d ", numbers3[i]);
        }
    }

    printf("\n");
    return 0;
}

int duplicate(int num1, int num2)
{
    if (num1 == num2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}