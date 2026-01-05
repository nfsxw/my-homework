#include <stdio.h>
int main()
{
    float sum = 0;
    float x = 0;
    int n = 0;
    
    printf ("Enter the number of digits: \n");
    if((scanf ("%d", &n)) == 1)
    {
        if (n >= 1)
        {
            while (n > 0)
            {
                if ((scanf ("%f", &x)) == 1)
                {
                    sum += x;
                    n -= 1;
                }
                else
                {
                    break;
                }
            }
            if (n > 0)
            {
                printf ("The number of digits entered is less than the number specified at the beginning.");
            }
            else
            {
                printf ("Sum total: %.2f", sum);
            }   
        }
        else
        {
            printf ("Empty consequence.");
        }
    }
    else 
    {
        printf ("Number of digits must be integer.");
    }
}