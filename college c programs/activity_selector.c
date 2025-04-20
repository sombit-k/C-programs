#include<stdio.h>


void main()
{
	int s[100],a[100],f[100],pos[100],n,i,m,k,j,t;
	printf("Enter the numbers of activities: ");
	scanf("%d",&n);
	printf("Enter the  start activities: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	printf("Enter the finish activities: ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&f[i]);
        }
	for(i=0;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(f[j]<f[j-1])
			{
			t=f[j];
			f[j]=f[j-1];
			f[j-1]=t;

			t=s[j];
                        s[j]=s[j-1];
                        s[j-1]=t;
			}
		}
	}
	printf("\nstart: ");
        for(i=0;i<n;i++)
        {
                printf("%d ",s[i]);
        }
	 printf("\nfinish: ");
        for(i=0;i<n;i++)
        {
                printf("%d ",f[i]);
        }
	 printf("\npos: ");
        for(i=0;i<n;i++)
        {
                printf("%d ",pos[i]);
        }


	k=0;
	a[k]=0;
	i=0;
	for(m=1;m<n;m++)
	{
		if(s[m]>=f[i])
		{
		k=k+1;
		a[k]=pos[m];
		i=m;
		}
	}
	printf("The activities are: ");
	for(m=0;m<=k;m++)
        {
                printf("activity%d  ",a[m]+1);
        }
}
