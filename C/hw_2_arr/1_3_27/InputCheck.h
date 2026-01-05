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