#include <stdio.h>
float calc(float, char, float);
int main()
{
    int a , b;
    char op;
    while((scanf("%d", &a)) == 1)
    {
        scanf("%d %c %d", &a, &op, &b);
        printf ("%.2f", calc(a , op, b));
    }
    return 0;
}

float calc(float a, char op, float b)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }
    else if (op == '/')
    {
        return a / b;
    }
    else
    {
        return 0;
    }
}