#include<stdio.h>

void quickSort(int arr[],int start, int end);

void quickSort(int arr[],int start, int end)
{

}
void printArray(int arr[9],int start, int size)
{
    printf("%d,%d",arr[start],arr[size]);
    // printf("%d",size);
    // for(int i=0;i<size;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
}
void main()
{
    int arr[9]={8,2,5,3,9,4,7,6,1};

    int size=sizeof(arr)/sizeof(arr[0]);

    printf("\n print array--\n");
    printArray(arr,0,size-1);

}