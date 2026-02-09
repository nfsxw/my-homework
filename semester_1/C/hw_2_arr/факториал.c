#include <stdio.h>

int rec(int);
int main()
{
    int n;
    while((scanf("%d", &n)) == 1)
    {
        scanf("%d", &n);
        printf("%d", rec(n));
    }
    return 0;
}

int rec(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * rec(n - 1);
}