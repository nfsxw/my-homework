#include <stdio.h>
int main()
{
    float first, x;
    int last;
    int n = 1;
   
    printf("Enter first digit: \n");
    if((scanf("%f", &first)) == 1)
    {
        printf("Enter your digit: ");
        while((scanf("%f", &x)) == 1)
        {
            n++;
            if(x == first)
            {
                last = n;
            }
        }
        if (n == 1)
        {
            printf ("Sequense contains only one digit.");
        }
        else
        {
            printf ("Number of the last digit: %d", last);
        }
    }
    else
    {
        printf ("Empty sequence.");
    }
}