#ifndef QUICKSORT_H
#define QUICKSORT_H
#define MAX_SIZE 1000

int InputArray(int[]);
int FillRandom(int arr[], int size);
void PrintArray(int arr[], int len);
void Swap(int*, int *b);
void SortingAsc(int arr[], int len);
void SortingDesc(int arr[], int len);
int InputChoice(int arr[]);
float SortChoice(int arr[], int len);

#endif