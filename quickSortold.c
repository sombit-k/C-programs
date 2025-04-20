#include<stdio.h>

int partition(int a[5],int l,int h)
{
    pivot=a[l];
    int i,j,t;
    i=l;
    j=h;
    while(i<=j)
    {
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--
        }while(a[j]>pivot);
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        t=a[l];
        a[l]=a[j];
        a[j]=t;
    }
    return j;
}

void quickSort(int a[] ,int l, int h)
{
    if(l<h)
    {
        j=partition(l,h);
        quickSort(l,j);
        quickSort(j+1,h);
    }
}

int main()
{
    int a[6] = {1,4,3,5,2,9999};
    quickSortarray(a[6],0,5);
    
}



