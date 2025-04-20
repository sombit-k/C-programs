#include<stdio.h>

int binarys(int*a,int f, int e,int k)
{
	printf("k is %d\n",k);
	int mid;
	if(e<=f)
	{
	return -1;
	}
	mid = (f+e)/2+1;
	printf("mid element  is %d\n",a[mid]);
	if(a[mid]==k)
		return mid;
	else if(a[mid]<k)
		binarys(a,mid-1,e,k);
	else
		binarys(a,f,mid+1,k);
}


void main()
{
	int n,a[100],i,j,t,k,b;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n-i-1;j++)
		{	
			if(a[j+1]<a[j])
			{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
               printf("%d ",a[i]);
	printf("Enter the element to find: ");
	scanf("%d",&k);
	b=binarys(a,0,n-1,k);
	if(b!=-1)
	{
	printf("Element found! at index %d",b);
	}
	else
	{
	printf("Element not found!");
	}
}



