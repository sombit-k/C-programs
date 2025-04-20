#include<stdio.h>

struct JOB{
	int name;
	int profit;
	int deadline;
};

void main()
{
	struct JOB a[100],t;
	int c,n,i,j,s[100],m,maxp;
	maxp=0;
	printf("Enter the number of jobs: ");
	scanf("%d",&n);
	printf("--Enter the jobs--\n");
	for(i=0;i<n;i++)
	{
		printf("JOB %d\n",(i+1));
		printf("Enter Profit: ");
		scanf("%d",&a[i].profit);
		printf("Enter Deadline: ");
                scanf("%d",&a[i].deadline);
		a[i].name=i+1;
	}
	m=a[0].deadline;
	for(i=1;i<n;i++)
        {
                m=m>a[i].deadline?m:a[i].deadline;
        }


	//init slots with -1
	for(i=0;i<m;i++)
        {
             	s[i]=-1;
        }
	




	//sort on the basis of profits	
	for(i=0;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(a[j].profit>a[j-1].profit)
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
			
		}
	}
	printf("\nSorted jobs on basis of profit\n");
	for(i=0;i<n;i++)
        {
                printf("Job:%d Profit: %d deadline: %d\n",a[i].name,a[i].profit,a[i].deadline);

        }
	for(i=0;i<n;i++)
	{
		c=a[i].deadline-1;
		while(s[c]!=-1 || c==-1)
			c--;
		if(s[c]==-1)
		{
			s[c]=i;
		}
	}
	printf("Job sequence is: ");
	for(i=0;i<m;i++)
	{
		printf("Job%d ",a[s[i]].name);
		maxp+=a[s[i]].profit;
	}
	printf("\nMax profit: %d",maxp);

}
