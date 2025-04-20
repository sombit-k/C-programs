#include<stdio.h>
void heapify(int arr[],int n,int i)
{
	int largest,l,r,t;
	largest=i;
	l=2*i+1;
	r=2*i+2;
	if(l<n && arr[l]>arr[largest])
	{
	largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
	largest=r;
	}
if(largest!=i)
	{
	t=arr[largest];
	arr[largest]=arr[i];
	arr[i]=t;
	heapify(arr,n,largest);
	}
}
void heapsort(int arr[],int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
{
	heapify(arr,n,i);
}
	for(i=n-1;i>0;i--)
	{
	temp=arr[0];
	arr[0]=arr[i];
	arr[i]=temp;
	heapify(arr,i,0);
	}
}
void p(int arr[],int n)
{
int i;
for(i=0;i<n;i++)
	printf("%d ",arr[i]);
printf("\n");
}

void main()
{
	int n,i;
	printf("Enter the number of elements:");
	scanf("%d",&n);int a[n];
	printf("Enter the elements: ");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
	heapsort(a,n);
	printf("The array after sorting: ");
	p(a,n);

}

