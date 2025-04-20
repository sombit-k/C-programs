
#include<stdio.h>
void main()
{
	int m,n,p,q,i,j,a[100][100],b[100][100],c[100][100];
	printf("Enter the dimensions of the first matrix: \n");
	scanf("%d %d",&m,&n);	
	printf("Enter the elements of the first matrix: \n");
	for(int i=0; i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the dimensions of the second matrix: \n");
	scanf("%d %d",&p,&q);	
	printf("Enter the elements of the second matrix: \n");
	for(int i=0; i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
		scanf("%d",&b[i][j]);
		}
	}

	if(p==m && q==n)
	{
	for(int i=0; i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		c[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("The difference of matr is :\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		printf("%d  ",c[i][j]);
		}
		printf("\n");
	}
	}
	else
	{
	printf("Matrix order doesnt match!!");
	}
	
}
