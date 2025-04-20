#include<stdio.h>
void quickSort(int *a,int start, int end,int size);
int partition(int *a,int start, int end,int size);
int partition(int *a,int start, int end,int size)
{
    int temp;
	int pivot=*(a+end);
	int i=start-1;
    for(int j=start;j<= end-1;j++)
    {
        if(*(a+j)<=pivot)
        {
            i++;
			temp=*(a+i);
			*(a+i)=*(a+j);
			*(a+j)=temp;
        }
    }
        i++;temp=*(a+i);
        *(a+i)=*(a+end);
        *(a+end)=temp;
        return i;
}
void quickSort(int *a,int start, int end,int size)
{
    if(end<=start)
    {
    return;
    };
    int pivot=partition(a,start,end,size);
    quickSort(a,start,pivot-1,size);
    quickSort(a,pivot+1,end,size);

}
void main()
{
	int c,n,k,i,mid,fi,li;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter a array:");
	printf("\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
	c=fi=0;
	li=n-1;
	quickSort(a,0,n-1,n);
		printf("\nArray is: ");
    for(i=0;i<n;i++)
	{
		printf("%d",*(a+i));
	}

	printf("\nEnter the element to search: ");
	scanf("%d",&k);
	printf("\n");
	
	while(fi<li)
	{
		mid=((fi+li)/2)+1;
		printf("%d\n",++c);
		if(a[mid]==k)
		{
			printf("Element found \n ");
			return;
		}
		else if(a[mid]>k)
		{
			li=mid-1;
		}
		else
		{
			fi=mid+1;
		}
	}
	printf("Element not found \n");\
}
