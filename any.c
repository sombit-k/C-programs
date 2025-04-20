#include<stdio.h>
#include<stdlib.h>
void dp()
{
    printf("Choices:\n1)Add in beggining\n2)Add at the end\n3)Add after an element\n4)Delete from beggining\n5)Delete from end\n6)Delete after an element\n7)Display choices\n8)Display linked list\n9)Stop\n");
}
struct node{
    int data;
    struct node* link;
};
struct node* newnode()
{
    return (struct node*)malloc(sizeof(struct node));
}
struct node* cn()
{
    int el;
    printf("Enter the element : ");
    scanf("%d",&el);
    struct node* p=newnode();
    p->data=el;
    p->link=NULL;
    return p;
}
void display(struct node* head)
{
    struct node* p=newnode();
    p=head;
    printf("\nThe values are: \n");
    while(p->link!=head && p->link!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }        
    printf("%d ",p->data);

struct node* fln(struct node* head) //find last node
{
    struct node* p=newnode();
    p=head;
    while(p->link!=head)
    p=p->link;
    return p;
}
struct node* fdn(struct node* head,int el) //find last node
{
    struct node* p=newnode();
    p=head;
    while(p->link!=head)
    {
        if(p->data==el)
        return p;
        p=p->link;
    }
    return NULL;
}
struct node* f2n(struct node* head) 
{
    struct node* p=newnode();
    struct node* q=newnode();
    q=head;
    p=q->link;
    while(p->link!=head)
    {
        p=p->link;
        q=q->link;
    }
    return q;
}
struct node* addb(struct node* head)
{
    struct node* temp=newnode();
    struct node* p=newnode();

    temp=cn();

    if(head->link==NULL)
    {
        temp->link=head;
        head->link=temp;
    }
    else{
        p=fln(head);
        temp->link=head;
        p->link=temp;
    }
    head=temp;
    return head;
}
struct node* adde(struct node* head)
{
    struct node* temp=newnode();
    temp=cn();
    if(head->link==NULL)
    {
        temp->link=head;
        head->link=temp;
    }
    else
    {
    struct node* ln=newnode();
    ln=fln(head);
    temp->link=head;
    ln->link=temp;
    }
    return head;
}
struct node* addn(struct node* head)//add after a node
{
    struct node* tn=newnode();//target node
    struct node* temp=newnode();
    int n;
    printf("Enter after which node you want to enter: ");
    scanf("%d",&n);
    tn=fdn(head,n);
    if(tn==NULL)
    {
        printf("Entered element is not present!");
        return head;
    }
    temp=cn();
    temp->link=tn->link;
    tn->link=temp;
    return head;
}
struct node* delb(struct node* head)
{
    struct node*p=newnode();
    struct node*ln=newnode();
    ln=fln(head);
    p=head;
    ln->link=head->link;
    head=head->link;
    free(p);
    return head;
}
struct node* dele(struct node* head)
{
    struct node*p=newnode();
    struct node*ln=newnode();
    struct node*secondln=newnode();
    ln=fln(head);
    secondln=f2n(head);
    p=ln;
    secondln->link=head;
    free(p);
    return head;
}
struct node* deln(struct node* head)
{
    struct node*p=newnode();
    struct node*tn=newnode();
    int n;
    printf("Enter the data of node after which you want to delete: ");
    scanf("%d",&n);
    tn=fdn(head,n);
    if(tn==NULL)
    {
        printf("Element not found\n");
        return head;
    }
    p=tn->link;
    tn->link=p->link;
    free(p);
    return head;
}
void main()
{
    int n,c;
    struct node* head=newnode();
    struct node* temp=newnode();
    head=cn();
    dp();
    while(1)
    {
        printf("\nYour choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    head=addb(head);
                    break;
            case 2:
                    head=adde(head);
                    break;
            case 3:
                    head=addn(head);
                    break;
            case 4:
                    if(head->link==NULL)
                    {
                        printf("\nUnderflow");
                        break;
                    }
                    head=delb(head);
                    break;
            case 5:
                    if(head->link==NULL)
                    {
                        printf("\nUnderflow");
                        break;
                    }
                    head=dele(head);
                    break;
            case 6:
                    head=deln(head);
                    break;
            case 7:
                    dp(head);
                    break;
            case 8:
                    display(head);
                    break;
            case 9:
                    return;
        }
    }
}
}