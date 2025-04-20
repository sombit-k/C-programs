#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[10000000];
struct result
	{
	int min;
	int max;
	};

struct result minmax(int*a,int f,int l)
{	struct result r;

	if(f==l)
	{
	r.min=a[f];
	r.max=a[f];	
	return r;
	}	
	if((l-f)==1)
	{
		if(a[l]>=a[f])
		{
		r.min=a[f];
        	r.max=a[l];
		}
		else
		{
		r.min=a[l];
                r.max=a[f];
		}
		return r;
	}
	else
	{
	struct result r,r1,r2;
	int mid;
	mid=(f+l)/2;
	r1=minmax(a,f,mid);
	r2=minmax(a,mid+1,l);
	r.max=r1.max>r2.max?r1.max:r2.max;
	r.min=r1.min<r2.min?r1.min:r2.min;
	return r;
	}
	
}

void main()
{
	struct result r;
	int n,i,j;
	int b[12]={5,10,20,50,100,200,500,1000,5000,10000,50000,100000};
	clock_t start,end;
	double ctime;	
	for(i=0;i<12;i++)
	{
	srand(time(0));

	for(j=0;j<b[i];j++)
	{
		a[i]=rand()%b[i]+1;		
	}
	start=clock();
	r=minmax(a,0,b[i]);
	end=clock();
	ctime=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Max element is: %d and Min element is: %d and time for %d elements is %lf\n",r.max,r.min,b[i],ctime);
	}
	
}

