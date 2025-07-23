void insertion_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                pos = j;
            }
        }
        if (i != pos)
        {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }
}