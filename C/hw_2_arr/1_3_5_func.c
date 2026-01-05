#include <stdio.h>
#define MAX_SIZE 1000

int Logic(float, float);
int main()
{
    /*
    numbers - investigated array.
    num - entered number.
    len - amount of numbers entered.
    min - minimal number of an array.
    minIndex - index of min.
    */

    float numbers[MAX_SIZE], num, min;
    int len = 0, minIndex;

    //Entering an array of numbers:

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

    min = numbers[0];
    minIndex = 0;
    for (int i = 0; i < len; i++)
    {
        if((Logic(min, numbers[i])) == 1)
        {
            min = numbers[i];
            minIndex = i;
        }     

    }
    printf("%.3f (%d)", min, minIndex);

    return 0;
}

int Logic(float min, float numbers)
{
    if (min > numbers)
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}