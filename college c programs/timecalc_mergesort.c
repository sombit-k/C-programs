#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int* a,int p,int q,int r)
{
	int i,j,k,n1,n2;
	n1=q-p+1;
	n2=r-q;
	int ri[n1+1],l[n2+1];
	for(i=0;i<n1;i++)
	{
		ri[i]=a[p+i];
	}
	for(i=0;i<n2;i++)
	{
		l[i]=a[q+i+1];
	}
	ri[n1]=l[n2]=99999;
	j=k=0;
	for(i=p;i<=r;i++)
	{
		if(ri[j]<=l[k])
		{
			a[i]=ri[j];
			j++;
		}
		else
		{
			a[i]=l[k];
			k++;
		}
	}
	
}

void mergesort(int* a,int p,int q)
{
	if(p>=q)
	{
	return;
	}
	int mid = (p+q)/2;
	mergesort(a,p,mid);
	mergesort(a,mid+1,q);
	merge(a,p,mid,q);
		
}

void main()
{
int i,a[1000000],j;
int b[12]={5,10,20,50,100,200,500,1000,5000,10000,50000,100000};

clock_t start,end;
double ctime;



for(j=0;j<12;j++)
{
srand(time(0));

for(i=0;i<b[j];i++)
{
	a[i]=rand()%b[j]+1;
}


start=clock();	
mergesort(a,0,b[j]);
end=clock();
//for(i=0;i<b[j];i++)
//{
//        printf("%d ",a[i]);
//}
//	printf("\n");



ctime=((double)(end-start))/CLOCKS_PER_SEC;	
printf("The time required for %d inputs is : %lf\n",b[j],ctime);
}
}

