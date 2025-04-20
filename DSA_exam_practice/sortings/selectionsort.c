#include<stdio.h>
void main()
{
	int j,i,a[100],n,t,min;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n-1;i++)
	{	
        min=i;
        for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
        t=a[min];
		a[min]=a[i];
		a[i]=t;
	}


	printf("The sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
	

