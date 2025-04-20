#include<stdio.h>

int binarySearch(int*a,int p,int q,int key)
{
    int mid;
    if(p <= q)
    {
        mid = (p + q) / 2;
        if(*(a + mid) > key)
            return binarySearch(a, p, mid - 1, key);
        else if(*(a + mid) < key)
            return binarySearch(a, mid + 1, q, key);
        else
            return mid;
    }
    return -1;
}

void main()
{
    int a[100];
    int n, key, b, t;
    printf("Enter the array size: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    
    // Bubble sort to sort the array
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j + 1] < a[j])
            {
                t = a[j + 1];
                a[j + 1] = a[j];
                a[j] = t;
            }
        }
    }
    
    b = binarySearch(a, 0, n - 1, key);
    if(b != -1)
        printf("The key found at index %d", b);
    else
        printf("Key not found");
}
