#include <stdio.h>
int main()
{
    float max,x;
    int ind, n = 1;

    if ((scanf("%f", &x)) != 1)
    {
        return 0;
    }
    else
    {
        max = x;
        ind = n;
        while ((scanf("%f", &x)) == 1)
        {
            n++;
            if (x > max)
            {
                max = x;
                ind = n;
            }
        }
        printf("%d", ind);
    }

}