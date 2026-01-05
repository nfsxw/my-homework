#include <stdio.h>
int main()
{
    float sum = 0;
    float sum1 = 0;
    float res;
    float x;
    int n = 0;

    printf ("Enter your number: \n");
    while ((scanf ("%f", &x)) == 1)
    {
        sum += x;
        sum1 += x*x;
        n++;
    }
    if (n == 0)
    {
        printf ("Empty sequence.");
    }
    else
    {
        res = (( sum1 / n ) - ( sum / n )*( sum / n ));  
        printf ("Dispersion: %.2f", res);
    }
}