#include<stdio.h>

struct activity{
	int a;
	int s;
	int f;
};

void main()
{	
	int n,i,j,m,k;
	struct activity acts[100];
   	struct activity ans[100];
	struct activity temp;
	printf("Enter the number of activities: ");	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{ 
		printf("Enter the start and finish of activity %d:",i+1);
		scanf("%d",&acts[i].s);
		scanf("%d",&acts[i].f);
		acts[i].a=i+1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(acts[j].f>acts[j+1].f)
			{
				temp=acts[j];
				acts[j]=acts[j+1];
				acts[j+1]=temp;
			}
		}
	}
	i=0;k=0;
	ans[k]=acts[0];
	for(m=1;m<n;m++)
	{
		if(acts[m].s>=acts[i].f)
		{
		k=k+1;
		ans[k]=acts[m];
		i=m;
		}
	}
	for(i=0;i<=k;i++)
	{
		printf("Activity%d ",ans[i].a);
	}
}
