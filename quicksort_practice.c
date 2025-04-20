#include<stdio.h>

void swap(int*a,int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int*a, int p,int r)
{
    int i,j,pivot=a[r];
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(*(a+j)<pivot)
        {
            i++;
            swap((a+j),(a+i));
        }
    }
    swap((a+i+1),(a+r));
    return i+1;
    
}

void quicksort(int*a,int p, int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

void main()
{
    int i,n;
	printf("Enter the number of elements of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
    quicksort(a,1,n);
	printf("The sorted array is :\n ");
        for(i=1;i<=n;i++)
        {
                printf("%d ",a[i]);
        }
}


