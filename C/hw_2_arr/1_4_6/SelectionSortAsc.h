void SelectionSortAsc(int arr[], int len)
{
    if (len <= 1) return;
    for(int n = 0; n < len - 1; n++)
    {        
    int maxInd = 0, lastUnsorted = len - 1 - n;
    for(int i = 0; i <= lastUnsorted; i++)
    {
        if (arr[i] > arr[maxInd])
        {
            maxInd = i;
        }
    }
    int temp = arr[lastUnsorted];
    arr[lastUnsorted] = arr[maxInd];
    arr[maxInd] = temp;
    }
}