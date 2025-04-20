#include<stdio.h>
void main()
{
    int arr[9]={8,2,5,3,9,4,7,6,1};

    int end=sizeof(arr)/sizeof(arr[0]);
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("%p\n",arr);
    printf("%d\n",size);
    printf("%d\n",end);

    int *p=arr;
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

}