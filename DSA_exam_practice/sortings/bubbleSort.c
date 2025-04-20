#include<stdio.h>
void main()
{
	int j,i,a[100],n,t;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{	for(j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
	

