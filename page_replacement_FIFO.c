#include<stdio.h>

void display(int*a,int n)
{
	printf("The Queue is : ");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}
void enqueue(int*a,int*r,int el,int n)
{
	a[*r]=el;
    *r=(*r+1)%n;
}

int exists(int*a,int el,int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==el)
            return 1;
	}
    return 0;
}

void main()
{
	int n,r,el,fs,pf,i;
    r=0;
    pf=0;
    printf("Enter the frame size: ");
	scanf("%d",&fs);
	printf("Enter the size of the reference string: ");
	scanf("%d",&n);
    int q[fs],a[n];

    for(i=0;i<fs;i++)
    {
        q[i]=-1;
    }


    printf("Enter the reference string: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
            
        if(exists(q,a[i],fs))
        {
            continue;
        }
        enqueue(q,&r,a[i],fs);
        pf++;
    }
    display(q,fs);
    printf("\nThe page fault with FIFO PGR is: %d",pf);
}
