#include <stdio.h>
int main()
{
	float x = 0;
	float sum = 0;
	float am;
	int n = 0;
	int k;

printf ("Enter your number: \n");
while ((k = scanf ("%f", &x)) == 1)
{
	sum += x;
	n++;
}
 if (n == 0)
{
 	printf ("Empty sequence.");
}
else
{
    am = sum / n;
 	printf ("Arithmetic mean: %.2f", am);
}
return 0;
}