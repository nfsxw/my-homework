#ifndef SORT_RES_H
#define SORT_RES_H

#define MIN 0
#define MAX 1000000
#define STEP 100000
#define REPS 20
#define SORT_CHOISE_MSG "Choose: Quick sort (a) / Merge sort (b)"
#define ASC_DESC_MSG "Measure ascending sort (a) / descending sort (b)"

extern char sort_type[20];
extern int *lens, fin_len;
extern double *times;

int Logic();
int Initialization();
int Choose_type_of_sort();
char Input_check(const char*);
int Q_sort();
int M_sort();
void Quick_sort_asc(int*, int);
void Quick_sort_desc(int*, int);
void Swap(int*, int*);
void Merge_sort_adapter_asc(int*, int);
void Merge_sort(int*, int, int, void (*)(int*, int, int, int));
void Merge_asc(int*, int, int, int);
void Merge_sort_adapter_desc(int*, int);
void Merge_desc(int*, int, int, int);
int Time_mes(void (*)(int*, int));
void Fill_random(int*, int);
void Print_lens_times();
void Save_to_CSV(const char* filename);
void Mem_clear();

#endif