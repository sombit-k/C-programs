#include<stdio.h>

int partition(int*a ,int p,int r)
{
	int j,i,x,t;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
	if(a[j]<=x)
	{
	i++;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
	}
	}
	t=a[1+i];
	a[i+1]=a[r];
	a[r]=t;
	return i+1;
}


void quicksort(int*a,int p,int r)
{
	if(p>r)
	return;
	int q;
	q=partition(a,p,r);
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);
}

void main()
{
	int n,i,j,a[100];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	quicksort(a,0,n);
	printf("The sorted array is:");
	for(i=0;i<n;i++)
        {
        printf("%d ",a[i]);
        }
}
