#include<stdio.h>
void main()
{
	int t,i,j,n,a[100],min;
	printf("Enter the number of array elements: \n");
	scanf("%d",&n);
	printf("Enter the array elements :\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	printf("\nSorting array..\n");
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
 	   t=a[i];
 	   a[i]=a[min];
  	  a[min]=t;
 	}
	printf("Sorted array is:\n");
	for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
 }
