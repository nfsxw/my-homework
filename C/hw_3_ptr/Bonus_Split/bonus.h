#ifndef BONUS
#define BONUS
#define MAX_LEN 1000

extern char *text;
extern char *septs;
extern char **tokens;
extern int text_len, septs_len, num_of_tokens;

int Allocate_arr();
int Input_string(char*);
int Fill_arr();
int Create_tokens(int, int, int*);
int ArrCheck();
int Clear_mem();
int logic();
int Count_tokens();

#endif 