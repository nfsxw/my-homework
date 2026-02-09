#include <stdio.h>
int main()
{
    float min, max, x;
    printf("Enter your digit: \n");
    if ((scanf("%f", &x)) == 1)
    {
        min = x;
        max = x;
        while((scanf("%f", &x)) == 1)
        {
            if (x > max)
            {
                max = x;
            }
            else
            {
                if (x < min)
                {
                    min = x;
                }
            }
        }
        printf("Max digit: %.2f \n", max);
        printf("Min digit: %.2f \n", min);
    }
    else
    {
        printf("Empty sequence. ");
    }
}