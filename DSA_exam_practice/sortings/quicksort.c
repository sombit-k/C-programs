#include<stdio.h>
int partition(int*a,int p,int r)
{
    int x,i,t,j;
    x=a[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            t=a[j];
            a[j]=a[i];
            a[i]=t; 
        }
    }
    i++;
        t=a[i];
        a[i]=a[r];
        a[r]=t;
        return i;
}

void quicksort(int* a,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

void main()
{
	int j,i,a[100],n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    quicksort(a,0,n-1);
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}