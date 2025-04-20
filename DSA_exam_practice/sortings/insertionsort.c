#include<stdio.h>
void main()
{
	int j,i,a[100],n,t,min;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

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
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
	

