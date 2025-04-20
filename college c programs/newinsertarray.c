#include<stdio.h>

void insertfirst(int* a, int el,int n);
void insertlast(int* a, int el, int n);
void insert(int* a, int el, int n);
void main()
{
int n;
printf("Enter the size of array: \n");
scanf("%d",&n);
int i, a[n+1];
printf("Enter the elements of array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element you want to enter:\n");
int el;
scanf("%d",&el);
printf("Enter the index you want to enter the element first(1)  or last(0) or kth(-1) index:\n");
int c;

scanf("%d",&c);
switch(c)
{
case 1: insertfirst(a,el,n);
	break;
case 0: insertlast(a,el,n);
	break;
case -1: insert(a,el,n);
	break;
default: printf("Worng input");
}
}


void insertfirst(int*a, int el,int n){
for(int i=n;i>0;i--)
{
*(a+i)=*(a+i-1);
}
*(a)=el;
for(int i=0;i<=n;i++)
{
printf("%d ",*(a+i));
}
}

void insertlast(int*a,int el, int n)
{
*(a+n+1)=el;
for(int i=0;i<=n;i++)
{
printf(" %d",*(a+i));
}

}

void insert(int *a, int el,int n)
{
int k;
printf("Enter the position: \n");
scanf("%d",&k);
for(int i=n+1;i>k;i--)
{
*(a+i)=*(a+i-1);
}
*(a+k)=el;
for( int i=0;i<=n;i++)
{
printf("%d ",*(a+i));
}
}









