#include<stdio.h>

void display(int*a,int r,int n)
{
	printf("The Queue is : ");
	for(int i=r;i>0;i--)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}
void enqueue(int*a,int* r,int el,int n)
{
	*r=(*r+1)%n;
	a[*r]=el;
    display(a,*r,n);
}

void main()
{
	int n,r,c,el;
    n=4;
	r=0;
    int rs[20]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int a[4];
	while(1)
	{
		printf("\nThe rear is %d\n",r);
		printf("\nChoose: \n1) enqueue\n3) display\n4) stop\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d",&el);
				enqueue(a,&r,el,n);
				break;
			case 3: 
				display(a,r,n);
				printf("\n");
				break;
			case 4:
				printf("\nTerminating");
				return;
		}
	}
}
