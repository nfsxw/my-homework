#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bonus.h"

int Count_tokens()
{
    if(logic())
    {
        Clear_mem();
        return 1;
    }
    printf("Number of tokens: %d.\n", num_of_tokens);
    Clear_mem();
    return 0;
}
int Allocate_arr()
{
    if(!(text = malloc(sizeof(char) * MAX_LEN))) return 1;
    if(!(septs = malloc(sizeof(char) * MAX_LEN))) return 1;
    return 0;
}

int Fill_arr()
{
    text_len = Input_string(text);
    if (text_len == -1) return 1;

    septs_len = Input_string(septs);
    if (septs_len == -1) return 1;
    return 0;
}

int Clear_mem()
{
    if(text) free(text);
    if(septs) free(septs);
    if(tokens)
    {
        for (int i = 0; i < num_of_tokens; i++) 
        {
            free(*(tokens + i));
        }
        free(tokens);
    }  
    return 0;
}

int logic()
{
    if(Allocate_arr()) return 1;
    if(Fill_arr()) return 1;
    if((num_of_tokens = ArrCheck()) == -1) return 1;
    return 0;
}

int Input_string(char *entStr)
{
    printf("Enter your line:\n");
    if (fgets(entStr, MAX_LEN, stdin) != NULL)
    {
        int last_num = strlen(entStr) - 1;
        if ( last_num >= 0 && *(entStr + last_num) == '\n') 
        {
            *(entStr + last_num) = '\0';
        }
        return last_num;
    }
    else
    {
        return -1;
    }
}

int ArrCheck()
{
    int len = 0, start = 0, capacity = 1;

    if(!(tokens = (char**)malloc(sizeof(char*) * capacity))) return -1;

    for(int i = 0; i < text_len; i++)
    {
        if(len >= capacity)
        {
            capacity *= 2;
            char** temp = realloc(tokens, capacity * sizeof(char*));
            if (!temp) return -1;
            tokens = temp;
        }

        if(len >= MAX_LEN) break;

        for(int j = 0; j < septs_len; j++)
        {
            if(*(text + i) == *(septs + j))
            {
                int token_size = i - start;
                if (token_size == 0)
                {
                    start = i + 1;
                    break;
                }
                if((Create_tokens(token_size, start, &len)) == -1) return -1;
                start = i + 1;
                break;
            }
        }
    }
    int token_size = text_len - start;
    if (token_size > 0)
    {
        if((Create_tokens(token_size, start, &len)) == -1) return -1;
    }
    if(!(tokens = (char**)realloc(tokens, len * sizeof(char*)))) return -1;
    return len;    
}

int Create_tokens(int token_size, int start, int *len)
{
    if(!(*(tokens + *len) = calloc(token_size + 1, sizeof(char)))) return -1;
    memcpy(*(tokens + *len), (text + start), sizeof(char) * token_size);
    (*len)++;
    return 0;
}
