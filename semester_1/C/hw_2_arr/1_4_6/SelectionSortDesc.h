void SelectionSortDesc(int arr[], int len)
{
    if (len <= 1) return;
    for(int n = 0; n < len - 1; n++)
    {        
    int maxInd = n;
    for(int i = n + 1; i < len; i++)
    {
        if (arr[i] > arr[maxInd])
        {
            maxInd = i;
        }
    }
    int temp = arr[n];
    arr[n] = arr[maxInd];
    arr[maxInd] = temp;
    }
}