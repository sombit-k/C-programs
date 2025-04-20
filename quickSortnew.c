#include<stdio.h>

void quickSort(int *a,int start, int end,int size);
int partition(int *a,int start, int end,int size);

int partition(int *a,int start, int end,int size)
{
    int temp;
    int pivot=*(a+size);
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
        temp=*(a+i);
        *(a+i)=*(a+end);
        *(a+end)=temp;
    return i;
}
void quickSort(int *a,int start, int end,int size)
{
    if(end<=start)
    {
        
    for(int i=0;i<size;i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n");
    return;
    
    };
    

    int pivot=partition(a,start,end,size);
    quickSort(a,start,pivot-1,size);
    quickSort(a,pivot+1,end,size);

}

void main()
{
    int arr[9]={8,2,5,3,9,4,7,6,1};

    int end=sizeof(arr)/sizeof(arr[0]);
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("%p",arr);
    int *p=arr;
    printf("\n --QuickSort Array--\n");
    quickSort(p,0,end-1,size);

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

}