#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[100],n,s1[100],s2[100],sum1,sum2,t,i,k,l,j;
	printf("Enter the number of elements in set: ");
	scanf("%d",&n);
	printf("Enter the elements in the set: ");
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
	
	
	sum1=0;sum2=0;
	k=0;l=0;
	for(i=0;i<n-1;i++)
	{
		if(abs(sum1+a[i+1]-(sum2+a[i]))<=abs(sum1+a[i]-(sum2+a[i+1])))
		{
			
			sum1+=a[i+1];
			s1[k++]=a[i+1];
			sum2+=a[i];
                        s2[l++]=a[i];

		}
		else
		{
			sum1+=a[i];
                        s1[k++]=a[i];
			sum2+=a[i+1];
                        s2[l++]=a[i+1];

		}
	
	}
	printf("\nFirst subset: ");
	for(i=0;i<k;i++)
        {
               printf("%d ",s1[i]);

        }
	printf("\nSecond subset: ");
        for(i=0;i<l;i++)
        {
               printf("%d ",s2[i]);

        }
printf("\n");
}

