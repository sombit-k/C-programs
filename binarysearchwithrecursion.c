#include<stdio.h>

void quicksort(int* a,int s, int e);//s= start, n=end
int partition(int* a,int s, int e);
void swap(int *a,int i, int j);
int binarysearch(int*a,int s,int e,int k);
void swap(int *a,int i,int j)
{
    int temp;
    temp=*(a+i);
    *(a+i)=*(a+j);
    *(a+j)=temp;
}
int partition(int* a,int s, int e)
{
    int pivot=*(a+e);
    int i,j=s-1;
    for(i=s;i<=e-1;i++)
    {
        if(*(a+i)>=pivot)
        {
            j++;
            swap(a,i,j);
        }
    }
    j++;
    swap(a,i,j);
    return j;
}
void quicksort(int* a,int s, int e)
{
    if(e<=s)
    return;

    int pivot=partition(a,s,e);
    quicksort(a,s,pivot-1);
    quicksort(a,pivot+1,e);
}
int binarysearch(int*a,int s,int e,int k)
{
    if(e<=s)
    return 0;
    int mid=(s+e)/2+1;
    if(k==*(a+mid))
    {
        return 1;
    }
    if(*(a+mid)<k)
    s=mid+1;
    else if(*(a+mid)>k)
    e=mid-1;
    binarysearch(a,s,e,k);
}

void main()
{
	int n,i,k;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter a array:");
	printf("\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
    quicksort(a,0,n-1);
    printf("\nArray is: ");
    for(i=0;i<n;i++)
	{
		printf("%d",*(a+i));
	}

    printf("\nEnter the element to search: ");
	scanf("%d",&k);
	printf("\n");
    if(binarysearch(a,0,n-1,k)==0)
    {
        printf("Element not found");
        return;
    }
    printf("ELement found");

}