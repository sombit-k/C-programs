#include<stdio.h>

struct obj
	{	int name;
		float p;
		float w;
		float pw;
	};

void main()
{
	int n,i,j,c;
	struct obj a[100];
	struct obj temp;
	float tw,tp;

	printf("Enter the number of objects: ");
	scanf("%d",&n);
	
	printf("Enter the profits for objects: ");
	for(i=0;i<n;i++)
		{
			scanf("%f",&a[i].p);
			a[i].name=i;
		}

	printf("Enter the weights for objects: ");
        for(i=0;i<n;i++)
                scanf("%f",&a[i].w);
	printf("Enter the total weight: ");
		scanf("%f",&tw);
	for(i=0;i<n;i++)
              	a[i].pw=a[i].p/a[i].w;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j].pw>a[j+1].pw)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	i=n-1;
	for(i;i>=0&&tw>=0;i--)
	{
		if(tw<a[i].w)
		{
			tw=tw-a[i].w;
			tp+=a[i].pw*tw;
		}
		tw=tw-a[i].w;
		tp=tp+a[i].p;
	}
	printf("the total profit is: %f",tp);
      
}
