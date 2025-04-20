#include<stdio.h>
void main()
{
int t,i,j,n,a[100];
printf("Enter the number of array elements: \n");
scanf("%d",&n);
printf("Enter the array elements :\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\nSorting array..\n");


for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j+1]<a[j])
{
t=a[j+1];
a[j+1]=a[j];
a[j]=t;
}
}

}
printf("Sorted array is:\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
