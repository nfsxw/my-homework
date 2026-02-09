#include <stdio.h>
int main()
{
    float prNum, actNum;
    int amnt = 1, n, k = 0;

    if ((scanf("%d", &n)) == 1)
    {
        if ((scanf("%f", &prNum)) == 1)
        {
            while ((scanf("%f", &actNum)) == 1)
            {
                if (prNum == actNum)
                {
                    amnt++;
                }
                else
                {
                    prNum=actNum;
                    if (amnt >= n)
                    {
                        k++;
                    }
                    amnt = 1;
                }
            }
            if (amnt >= n)
            {
                k++;
            }
            printf("%d", k);
        }
        return 0;
    }
    return 0;
}