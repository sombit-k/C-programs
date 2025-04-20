#include<stdio.h>
void main()
{

	 int a[5][5],i,j,k,t;
	printf("Enter the elements of the row: ");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("a[%d][%d]: ",i,j);
		scanf("%d",&a[i][j]);
		}
	}

	printf("The unsorted matirx is: \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("%d\t",a[i][j]);		
		}
	printf("\n");
	}

	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)	
		{
		for(k=0;k<5-j-1;k++)
		{
		if(a[i][k+1]<a[i][k])
		{
		t=a[i][k+1];
		a[i][k+1]=a[i][k];
		a[i][k]=t;
		}
		}
		}
	}
	printf("After row sorting matirx is: \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("%d\t",a[i][j]);		}
	
	printf("\n");
	}

	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)	
		{
		for(k=0;k<5-j-1;k++)
		{
		if(a[k+1][i]<a[k][i])
		{
		t=a[k+1][i];
		a[k+1][i]=a[k][i];
		a[k][i]=t;
		}
		}
		}
	}


	printf("The matrix is : \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("%d\t",a[i][j]);
		}
	printf("\n");
	}


}


