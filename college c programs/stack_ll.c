#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};


struct node* n()
{
	return (struct node*)malloc(sizeof(struct node));
}
void main()
{
	int a,c,el;
	struct node* p=n();
	struct node* temp=n();
	printf("Enter the top element: ");
	scanf("%d",&a);
	struct node* head = n();
	head->data=a;
	head->link=NULL;
	
	printf("1)Push\n2)Pop\n3)Display\n4)Stop");
		
	while(1)
	{
	printf("\nYour choice : ");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		p=n();
		printf("Enter the data to be pushed: ");
		scanf("%d",&el);
		p->data=el;
		p->link=head;
		printf("%d pushed\n",p->data);
		head=p;
		break;
	case 2:
		if(head->link==NULL)
		{
			printf("Underflow\n");break;
		}
		temp=head;
		printf("%d has been popped!",temp->data);
		head=head->link;
		free(temp);
		break;
	case 3:
		p=head;
		printf("The stack is : \n");
		while(p->link!=NULL)
		{
			printf("%d\n",p->data);
			p=p->link;
		}
		printf("%d\n",p->data);
		break;
	case 4:
		return;
	}	

	}
	
}
