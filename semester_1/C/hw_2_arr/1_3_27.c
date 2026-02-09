#include <stdio.h>
#define MAX_SIZE 1000
int InputCheck(void);
void Init(int[], int);
void PascalRow(int[], int);
void PrintArray(int[], int);
int main()
{
    int n = InputCheck();
    int arr[n + 1];
    Init (arr, n);
    PascalRow(arr, n);
    PrintArray(arr, n);
    printf("\n");
    return 0;
}

int InputCheck(void)
{
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    while(n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid input! Enter n between 1 and %d: \n", MAX_SIZE);
        scanf("%d", &n);
    }
    return n;
}

void Init(int arr[], int n)
{
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = 0;
    }
}

void PascalRow(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            arr[j] += arr[j - 1];
        }
    }
}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
}