#include<stdio.h>

void delete(int*a,int el,int n);
void main()
{
int n,i,el;
printf("Enter the size of the array: \n");
scanf("%d",&n);
int a[n];
printf("Enter the elements of the array: \n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element to delete:");
scanf("%d",&el);

delete(a,el,n);
}

void delete(int *a,int el, int n)
{
int flag=0,index;
for(int i=0;i<n;i++)
{
if(*(a+i)==el)
{
flag=1;
index=i;
}
}

if(flag)
{
printf("The elements are: \n");
for(int i=0;i<index;i++)
{
printf("%d ",*(a+i));
}
for(int i=index+1;i<n;i++)
{
printf("%d ",*(a+i));
}
}
else
{
printf("element not found");
}
}
