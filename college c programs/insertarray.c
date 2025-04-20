#include<stdio.h>
void main()
{
int n;
printf("enter the size of array : \n");
scanf("%d",&n);
int el,k;
int a[n],b[n];
printf("Enter array elements");
for(int i= 0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("array elements are: \n");
for(int i=0;i<n;i++)
{
printf("%d",a[i]);
}
printf("\n Enter the element u want to enter and the index: \n");
scanf("%d %d",&el,&k);
for(int i=0;i<k;i++)
{
b[i]=a[i];
}
b[k]=el;
for(int i=k+1;i<n+1;i++)
{
b[i]=a[i-1];
}
for(int i=0;i<n+1;i++)
printf("%d ",b[i]);
}
