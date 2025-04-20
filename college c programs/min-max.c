#include<stdio.h>

struct result
	{
	int min;
	int max;
	};

struct result minmax(int*a,int f,int l)
{	struct result r;

	if(f==l)
	{
	r.min=a[f];
	r.max=a[f];	
	return r;
	}	
	if((l-f)==1)
	{
		if(a[l]>=a[f])
		{
		r.min=a[f];
        	r.max=a[l];
		}
		else
		{
		r.min=a[l];
                r.max=a[f];
		}
		return r;
	}
	else
	{
	struct result r,r1,r2;
	int mid;
	mid=(f+l)/2;
	r1=minmax(a,f,mid);
	r2=minmax(a,mid+1,l);
	r.max=r1.max>r2.max?r1.max:r2.max;
	r.min=r1.min<r2.min?r1.min:r2.min;
	return r;
	}
	
}

void main()
{
	struct result r;
	int a[100],n,i;
	printf("Enter the size of the list: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	r=minmax(a,0,n-1);
	printf("Max element is: %d and Min element is: %d\n",r.max,r.min);
	
}

