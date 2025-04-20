#include<stdio.h>

int t[100][100];


int c(int n,int k)
{	int i,j;
	if(t[n][k]!=0) return t[n][k];
	if(k==0 || n==k) return 1;
	else 
	t[n][k]= c(n-1,k-1)+c(n-1,k);
	return t[n][k];
}

void main()
{
	int i,j,n,k,val;
	printf("Enter the value of n and k: ");
	scanf("%d%d",&n,&k);
	val=c(n,k);
	printf("The value of c[n,k] is: %d",val);
}
