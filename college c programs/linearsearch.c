#include<stdio.h>
void main()
{
int n,i,s,a[100];
printf("Enter the size of the array:\n");
scanf("%d",&n);
printf("Enter array element:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element to search:\n");
scanf("%d",&s);
for(i=0;i<n;i++)
{
if(a[i]==s)
{
printf(" Element found");
return;
}
}
printf("Element not found");
}
