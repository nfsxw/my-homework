#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bonus.h"

char *text = NULL;
char *septs = NULL;
char **tokens = NULL;
int text_len, septs_len, num_of_tokens;

int main()
{
    if(Count_tokens()) return 1;
    return 0;
}