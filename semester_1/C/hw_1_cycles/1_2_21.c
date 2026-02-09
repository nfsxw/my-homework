#include <stdio.h>
int main()
{
    float first;
    float x;
    int n = 0;

    printf ("Enter first digit: \n");
    if ((scanf("%f", &first) == 1))
    {
    while ((scanf("%f", &x)) == 1)
    {
        if (first == x)
        {
            n++;
        }
    }
    printf("Number of repeats: %d", n);
    }
    else
    {
        printf("Empty sequence.");
    }
}