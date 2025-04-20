#include<stdio.h>



void merge(int*a,int p,int q,int r)
{
	int i,n1,n2,max,j,k;
	n1=q-p+1;
	n2=r-q;
	int l[n1+1],ri[n2+1];
	for(i=1;i<=n1;i++)
    	{
			printf(" %d",a[p+i-1]);
	        l[i]=*(a+p+i-1);
			max=max<l[i]?l[i]:max;
    	}
	for(i=1;i<=n2;i++)
		{
			ri[i]=*(a+q+i);
			max=max<ri[i]?ri[i]:max;
		}
	l[n1+1]=ri[n2+1]=max+1;
	i=1;j=1;
	printf("\nMerged array is: ");
	for(k=p;k<=r;k++)
	{
		if(l[i]<ri[j])
		{
			*(a+k)=l[i];
			i++;
		}
		else
		{
			*(a+k)=ri[j];
                j++;
		}
		printf("%d",a[k]);

	}
}

void mergesort(int*a,int p, int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}	
void main()
{
	int i,n;
	printf("Enter the number of elements of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}

	mergesort(a,1,n);

	printf("The sorted array is :\n ");
        for(i=1;i<=n;i++)
        {
                printf("%d ",a[i]);
        }
}

