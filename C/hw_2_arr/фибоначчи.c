#include <stdio.h>

int rec(int);
int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        printf("%d \n", rec(i));
    }
    return 0;
}

int rec(int n)
{
    if (n == 1 || n == 0) return n;

    return rec(n - 1) + rec(n - 2);
}