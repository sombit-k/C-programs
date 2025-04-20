#include<stdio.h>  
void heapify(int*a,int i,int n)
{
    int largest,l,r;
    largest=i;
    l=2*i+1;
    r=2*i+2;
    if(l<n && a[l]>*(a+largest))
    {
        largest=l;
    }
    if(r<n && a[r]>*(a+largest))
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=*(a+largest);
        *(a+largest)=*(a+i);
        *(a+i)=temp; 
        heapify(a,largest,n);
    }
}
void heapsort(int*a,int n)
{
    int i,temp;
    //buildmax heap
    for(i=n/2-1;i>=0;i--)
    heapify(a,i,n);
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,0,i);
    }
}   
void main()
{
    int n;
    printf("Enter the size of the heap: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}