#include<stdio.h>
void main()
{
	int a[100],n,i,j,t;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	for(i=0;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(a[j]<a[j-1])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
			
		}
	}
	printf("The sorted element is: \n\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
	
