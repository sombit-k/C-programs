#include<stdio.h>

int partition(int*a,int p,int q)
{
	int x=a[q];
	int i,j,t;
	i=p-1;
	for(j=p;j<q;j++)
	{
		if(a[j]<=x)
		{
			i++;	
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}

			
	}
	t=x;
        a[q]=a[i+1];
        a[i+1]=t;
        return i+1;
}

void quicksort(int*a,int p,int q)
{
	if(p<q)
	{
	int r=partition(a,p,q);
	quicksort(a,p,r-1);
	quicksort(a,r+1,q);
	}
}

int binarySearch(int* a,int p,int q,int k)
{
	if(q<=p) return -1;
	int mid=(p+q)/2+1;
	if(a[mid]==k) return mid;
	else if(a[mid]<k)  binarySearch(a,mid+1,q,k);
	else  binarySearch(a,p,mid-1,k);
				
}

void main()
{
	int a[100], n,i,k,b;
	
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n);
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
                printf("%d ",a[i]);
	printf("\n");
	//array sorted
	
	printf("Enter the value to find: ");
	scanf("%d",&k);
	b=binarySearch(a,0,n,k);
	if(b==-1)
	{
		printf("Value not found");return;
	}
	printf("Value found at : %d",b);
}

