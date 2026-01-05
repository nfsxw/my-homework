#include <stdio.h>
int main()
{
    float x;
    int pos = 0;
    int neg = 0;
    int zer = 0;

    printf ("Enter your number: ");
    while ((scanf ("%f", &x)) == 1)
    {
        if (x > 0)
        {
            pos++;
        }
        else
        {
            if (x < 0)
            {
                neg++;
            }
            else
            {
                zer++;
            }
        }
    }
    printf ("Positive: %d \n", pos);
    printf ("Negative: %d \n", neg);
    printf ("Zero: %d \n", zer);
}