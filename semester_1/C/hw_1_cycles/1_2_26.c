#include <stdio.h>
int main()
{
    float min, x;
    int amnt = 1;
    if ((scanf("%f", &x)) == 1)
    {
        min = x;
        while ((scanf("%f", &x)) == 1)
        {
            if (x == min)
            {
                amnt++;
            }
            else
            {
                if(x < min)
                {
                    amnt = 1;
                    min = x;
                }
            }
        }
        printf("%d", amnt);
    }
    return 0;
}