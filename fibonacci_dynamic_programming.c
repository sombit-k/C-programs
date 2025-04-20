#include<stdio.h>

int memo[100];

int fib(int n)
{
	if(memo[n]) return memo[n];
	else if(!n) return 0;
	else if(n<2) return 1;
	else 
	memo[n]=fib(n-1)+fib(n-2);	
	return memo[n];
}

void main()
{
	int n,i;
	printf("Enter the number of terms of fibonacci series: ");
	scanf("%d",&n);
	for(i=0;i<100;i++)
	{
		memo[i]=0;
	}
	printf("The fibonacci terms are: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",fib(i));
	}
	
}
