#include<stdio.h>

int fibo(int n)
{
	if(n==0)
	return 0;
	else if(n==1)
	{
	return 1;
	}
	return fibo(n-1)+fibo(n-2);
}

void main()
{
	int n,el,i;
	printf("Enter upto which term terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	el=fibo(i);
	printf("%d ",el);
	}
}
