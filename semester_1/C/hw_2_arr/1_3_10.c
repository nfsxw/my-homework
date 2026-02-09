#include <stdio.h>
#define MAX_SIZE 1000

float HalfSum(float, float);
int main()
{
    float numbers[MAX_SIZE], num, prevNum, curNum;
    int len = 0;

    //Input:

    for (int i = 0; i < MAX_SIZE; i++) 
    {
        if ((scanf("%f", &num)) == 1)
        {
            numbers[i] = num;
            len++;
        }
        else
        {
            break;
        }
    }

    //Logic:

    prevNum = numbers[0];
    for (int i = 0; i < len; i++)
    {
        if (i != 0 && i != len - 1)
        {
            curNum = numbers[i];
            numbers[i] = HalfSum (prevNum , numbers[i + 1]);
            prevNum = curNum;
        }
    }

    //Output:

    for (int i = 0; i < len; i++)
    {
        printf ("%.2f ", numbers[i]);
    }
    printf("\n");

    return 0;   
}

float HalfSum(float prev, float foloww)
{
    return (prev + foloww) / 2;
}