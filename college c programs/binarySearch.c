#include<stdio.h>
void main()
{
	int s,t,i,j,n,a[100],mid,midi;
	printf("Enter the number of array elements: \n");
	scanf("%d",&n);
	printf("Enter the array elements :\n");
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	printf("Enter element to search:\n");
	scanf("%d",&s);
	midi=n/2;
	printf("Mid term = %d\n\n",mid);
	while(midi<n && midi >0)
	{	
		mid=a[midi];
		if(mid==s)
		{
			printf("Element found !!\n");
			return;
		}
		if(mid<=s)
		{
			midi=(n+midi)/2;
		}
		else
		{
			midi=(0+midi)/2;
		}
	}
	printf("Element not found");
}
