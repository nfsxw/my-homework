#include <stdio.h>
int main()
{
    float x, min;
    int first, last, n = 1;

    if((scanf("%f", &x)) == 1)
    {
        min = x;
        first = n;
        last = n;

        while ((scanf("%f", &x)) == 1)
        {
            n++;
            if (x == min)
            {
                last = n;
            }
            else
            {
                if (x < min)
                {
                    min = x;
                    first = n;
                    last = n;
                }
            }
        }
        printf ("%d %d", first, last);
    }
    return 0;
}