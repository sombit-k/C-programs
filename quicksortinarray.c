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
        if(*(a+j)>=pivot)
        {
            i++;
            temp=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=temp;
        }  
    }
        i++;
        temp=*(a+i);
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
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    int *p=arr;
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&*(p+i));
    }

    int end=sizeof(arr)/sizeof(arr[0]);
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nBase address: %p--- end,size= %d\n\n",arr,end);
    printf("Unsorted array: - ");
for(int i=0;i<size;i++)
    {
        printf("%d ",*(p+i));
    }
    printf("\n");
    quickSort(p,0,end-1,size);
printf("\nQuickSorted Array: - ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",*(p+i));
    }
}