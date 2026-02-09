#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <direct.h>
#include <sys/stat.h>
#include "Sort_Res.h"

char sort_type[20] = {0};
int *lens = NULL, fin_len;
double *times = NULL;

int Logic()
{
    if(Initialization()) return 1;
    if(Choose_type_of_sort()) return 1;
    Print_lens_times();
    Save_to_CSV("Research_results.csv");
    return 0;
}

int Initialization()
{
    srand((unsigned int)time(NULL));
    fin_len = ((MAX - MIN) / STEP) + 1;
    if (!(lens = calloc(fin_len, sizeof(int)))) return 1;
    if (!(times = calloc(fin_len, sizeof(double)))) return 1;
    return 0;
}

int Choose_type_of_sort()
{
    char c = Input_check(SORT_CHOISE_MSG);
    switch (c)
    {
        case 'a':
            if(Q_sort()) return 1;   
            break;
        case 'b':
            if(M_sort()) return 1;
            break;
    }
    return 0;
}

char Input_check(const char *msg)
{
    char c;
    printf(msg);
    scanf (" %c", &c);
    while (c != 'a' && c != 'b')
    {
        printf(msg);
        scanf (" %c", &c);
    }
    return c;
}

int Time_mes(void (*Func)(int*, int))
{
    printf("Computing...\n");
    for(int i = 0; i < fin_len; i++)
    {
        int cur_len = MIN + STEP * i, *arr = NULL, *orig = NULL;
        *(lens + i) = cur_len;

        if (!(arr = calloc(cur_len, sizeof(int)))) return 1;
        if (!(orig = calloc(cur_len, sizeof(int))))
        {
            free(arr);
            return 1;
        }

        Fill_random(arr, cur_len);
        memcpy(orig, arr, sizeof(int) * cur_len);

        clock_t start, end;
        start = clock();
        for(int j = 0; j < REPS; j++)
        {
            memcpy(arr, orig, sizeof(int) * cur_len);
            Func(arr, cur_len);
        }
        end = clock();
        double cur_time = (double)(end - start) / (REPS * (double)CLOCKS_PER_SEC);

        *(times + i) = cur_time;

        float prog = ((i + 1)*100) / fin_len;
        printf("\rYour progress: %.2f%%", prog);
        fflush(stdout);
        
        if(arr) free(arr);
        if(orig) free(orig);
        arr = NULL;
        orig = NULL;
    }
    printf("\n");
    return 0;
}

void Fill_random(int *arr, int size)
{  
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = -1000 + rand() % 2001;
    }
}

void Print_lens_times()
{
    for(int i = 0; i < fin_len; i++)
    {
        printf("Size: %d, Time: %.9f\n", *(lens + i), *(times + i));
    }
}

void Save_to_CSV(const char* filename) 
{
    #ifdef _WIN32
        _mkdir("results");
    #else
        _mkdir("results", 0755);
    #endif

    char full_path[256];
    snprintf(full_path, sizeof(full_path), "results/%s.csv", sort_type);
    
     int counter = 0;
    char temp_path[256];
    strcpy(temp_path, full_path);

    while (1) 
    {
        #ifdef _WIN32
                if (_access(temp_path, 0) == -1) break;  // файл не существует
        #else
                if (access(temp_path, F_OK) == -1) break;  // файл не существует
        #endif
        counter++;
        snprintf(temp_path, sizeof(temp_path), "results/%s_%d.csv", sort_type, counter);
    }

    FILE *file = fopen(temp_path, "w");
    if (!file) 
    {
        perror("Can't create file.\n");
        return;
    }

    fprintf(file, "Size;Time_sec\n");

    for (int i = 0; i < fin_len; i++)
    {
        fprintf(file, "%d;%.9f\n", *(lens + i), *(times + i));
    }

    fclose(file);
    printf("Data saved to: %s\n", temp_path);
}

void Mem_clear()
{
    if(lens) free(lens);
    if(times) free(times);
}