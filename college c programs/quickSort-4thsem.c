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



void main()
{
	int a[100], n,i,j;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The sorted array is: ");
	quicksort(a,0,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
		
	
}
