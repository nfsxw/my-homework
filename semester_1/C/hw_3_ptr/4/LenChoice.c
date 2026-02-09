#include <stdio.h>
#include "Arr_Input_Output.h"

int LenChoice(void)
{
int N;
scanf(" %d", &N);
while (N <= 0 || N > MAX_SIZE)
{
    printf("Invalid input, enter len again\n");
    scanf(" %d", &N);
}
return N;
}