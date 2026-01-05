#include <stdio.h>
#include <stdlib.h>
int main()
{
   float first, x;
   int n = 1;

   printf("Enter first digit: \n");
   if ((scanf("%f", &first)) == 1)
   {
    printf("Enter your digit: \n");
    while((scanf("%f", &x)) == 1)
    {
        n++;
        if (first == x)
        {
            printf("Serial number: %d", n);
            exit(0);
        }
    }
    printf("Sequence does not contain digits equal to the first. ");  
   }
   else
   {
    printf("Empty sequence.");
   }
}