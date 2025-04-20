#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node* link;
};

void dp()
{
    printf("Choices:\n1)Add in beggining\n2)Delete from beginning\n3)Add at the end\n4)Delete fromt the end\n5)Add after an element\n6)Delete after an element\n7)Display choices\n8)Display linked list\n9)Stop\n");
}

struct node* cn()
{
    int el;
    printf("Enter the element you want to enter: ");
    scanf("%d",&el);
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=el;
    p->link=NULL;
    return p;
}

struct node* ln(struct node* head)//last node
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    struct node* q=(struct node*)malloc(sizeof(struct node));
    p=head;
    q=p->link;
    while(q->link!=NULL)
    {
        p=q;
        q=q->link;
    }
    return p;
}

void display(struct node* head)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p=head;
    printf("\nThe values are: ");
    while(p->link!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("%d ",p->data);
}

struct node* addb(struct node* head)
{
    struct node* temp= malloc(sizeof(struct node));
    temp=cn();
    temp->link=head;
    head=temp;
    return head;
}

struct node* fn(struct node* head,int el)//find a node
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    struct node* q=(struct node*)malloc(sizeof(struct node));
    p=head;
    // q=p->link;
    while(p->link!=NULL)
    {
        if(p->data==el)
        {
            return p;
        }
        p=p->link;
    }
    return NULL;
}

struct node* dfn(struct node* head,int el)//find a node before a node
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    struct node* q=(struct node*)malloc(sizeof(struct node));
    p=head;
    q=p->link;
    while(q->link!=NULL)
    {
        if(q->data==el)
        {
            return p;
        }
        p=p->link;
        q=q->link;
    }
    return NULL;
}

void main()
{
    int el,c;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* temp= malloc(sizeof(struct node));
    struct node* p=(struct node*)malloc(sizeof(struct node));
    head=cn();
    dp();
    while(1)
    {
        printf("\nYour choice: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                temp=addb(head);
                head=temp;
                break;

            case 2:
                if(head->link==NULL)
                {
                    printf("Underflow!!!\n");
                    break;
                }
                el=head->data;
                temp=head;
                head=head->link;
                free(temp);
                printf("\nDeleted item is: %d\n",el);
                break;

            case 3:
                p=ln(head);//2nd last node
                p=p->link;//last node
                temp=cn();
                p->link=temp;
                break;

            case 4:
                if(head->link==NULL)
                {
                    printf("UNDERFLOW!!!\n");
                    break;
                }
                p=ln(head);//2nd last node
                temp=p->link;//last node
                el=temp->data;
                p->link=NULL;
                printf("\nThe deleted element is %d \n",el);
                free(temp);
                break;

            case 5:
                printf("\nAfter which element you want to insert? : ");
                scanf("%d",&el);
                temp=fn(head,el);
                if(temp==NULL)
                {
                    printf("Element not found!!\n");
                    break;
                }
                
                p=cn();
                p->link=temp->link;
                temp->link=p;
                
                break;
            case 6:
                printf("\nWhich element do you want to Delete? : ");
                scanf("%d",&el);
                temp=dfn(head,el);//node before the element
                if(temp==NULL)
                {
                    printf("Element not found!!\n");
                }
                else
                {
                    p=temp->link;
                    el=p->data;
                    temp->link=p->link;
                    free(p);
                    printf("\n%d was deleted",el);
                }
                break;
            case 7:dp();break;
            case 8:display(head);break;
            case 9:return;
        }
    }

}


