#include<stdio.h>
#include <limits.h>

void merge(int* a,int p,int q,int r)
{
	int i,j,k,n1,n2;
	n1=q-p+1;
	n2=r-q;
	int ri[n1+1],l[n2+1];
	for(i=0;i<n1;i++)
	{
		ri[i]=a[p+i];
	}
	for(i=0;i<n2;i++)
	{
		l[i]=a[q+i+1];
	}
	ri[n1]=[n2]=INT_MAX;
	j=k=0;
	for(i=p;i<=r;i++)
	{
		if(ri[j]<=l[k])
		{
			a[i]=ri[j];
			j++;
		}
		else
		{
			a[i]=l[k];
			k++;
		}
	}
	
}

void mergesort(int* a,int p,int q)
{
	if(p>=q)
	{
	return;
	}
	int mid = (p+q)/2;
	mergesort(a,p,mid);
	mergesort(a,mid+1,q);
	merge(a,p,mid,q);
		
}

void main()
{
	int a[100],n,i;
	printf("Enter the size of the list: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
        {
        printf("%d ",a[i]);
        }

}

