#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h, t;
    while(i < j)
    {
        while(a[i] <= pivot && i < h) i++;
        while(a[j] > pivot) j--;
        if(i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quickSort(int a[], int l, int h)
{
    if(l < h)
    {
        int j = partition(a, l, h);
        quickSort(a, l, j - 1);
        quickSort(a, j + 1, h);
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int j, i, *a, n;
    int b[12] = {5, 10, 20, 50, 100, 200, 500, 1000, 5000, 10000, 50000, 100000};
    srand(time(0));
    for(i = 0; i < 12; i++)
    {
        n = b[i];
        a = (int*)malloc(n * sizeof(int));
        start = clock();
        for(j = 0; j < n; j++)
        {
            a[j] = rand() % 100000 + 1;
        }
        quickSort(a, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time for %d is %f\n", n, cpu_time_used);
        free(a);
    }
    return 0;
}



