#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
};

struct node * n()
{
	return (struct node*)malloc(sizeof(struct node));
}

void main()
{
	int el,data,c;
	struct node* head=n();
	struct node* rear=n();
	struct node* p=n();
	struct node* temp=n();
	printf("Enter the first element: ");
	scanf("%d",&el);
	head->data=el;
	head->link=NULL;
	
	printf("Choices:\n1)Enqueue\n2)Dequeue\n3)Display\n4)Stop");
	
	while(1)
	{
	printf("\nYour choice : ");
	scanf("%d",&c);
	
	switch(c)
	{
	case 1:
		printf("Enter the data to enqueue: ");
		scanf("%d",&data);
		p=n();
		p->data=data;
		p->link=NULL;
		if(head->link==NULL)
		{
		head->link=p;
		}
		else
		{
		temp=head;
		while(temp->link!=NULL) 
			temp=temp->link;
		temp->link=p;
		}
		printf("%d enqueued!",data);
		break;
	case 2:
		temp=n();
		temp=head;
		head=head->link;
		printf("%d dequeued\n",temp->data);
		free(temp);
		break;
	case 3:
		p=head;
		printf("The queue is : \n");
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
