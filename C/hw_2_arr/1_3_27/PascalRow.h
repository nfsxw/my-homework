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