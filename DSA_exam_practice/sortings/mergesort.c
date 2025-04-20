#include<stdio.h>

void merge(int* a,int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1],R[n2+1];
    for(i=1;i<=n1;i++)
    {
        L[i]=a[p+i-1];
    }
    for(j=1;j<=n2;j++)
    {
        R[j]=a[q+j];
    }
    L[n1+1]=999999;
    R[n1+1]=999999;
    i=1;j=1;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;    
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        
    }
}

void mergesort(int*a,int p,int r)
{
    if (p<r)
    {
        int q;
        q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void main()
{
	int j,i,a[100],n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
    mergesort(a,1,n);
	printf("The sorted array is: ");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}