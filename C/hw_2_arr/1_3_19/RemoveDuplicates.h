int RemoveDuplicates(int arr[], int len1)
{
    int isNew, len2 = 0;
    for (int i = 0; i < len1; i++)
    {
        isNew = 1;
        for (int j = 0; j < len2; j++)
        {
            if(arr[i] == arr[j])
            {
                isNew = 0;
                break;
            }
        }
        if(isNew)
        {
        arr[len2] = arr[i];
        len2++;
        }
    }
    return len2;
}