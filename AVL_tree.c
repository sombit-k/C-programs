
#include <stdio.h>
#include <stdlib.h>
struct node {
    int k;
    struct node* l;
    struct node* r;
    int h;
};
int geth(struct node* n)
{
    if (n == NULL)
        return 0;
    return n->h;
}

struct node* createnode(int k)
{

    struct node* node= (struct node*)malloc(sizeof(struct node));
    node->k = k;
    node->l = NULL;
    node->r = NULL;
    node->h = 1; 
    return node;
}
int max(int a, int b) { return (a > b) ? a : b; }
int getbf(struct node* n)
{
    if (n == NULL)
        return 0;
    return geth(n->l) - geth(n->r);
}
struct node* rRotate(struct node* y)
{
    struct node* x = y->l;
    struct node* T2 = x->r;

    x->r = y;
    y->l = T2;
    y->h
        = max(geth(y->l), geth(y->r)) + 1;
    x->h
        = max(geth(x->l), geth(x->r)) + 1;

    return x;
}
struct node* lRotate(struct node* x)
{
    struct node* y = x->r;
    struct node* T2 = y->l;
    y->l = x;
    x->r = T2;

    x->h
        = max(geth(x->l), geth(x->r)) + 1;
    y->h
        = max(geth(y->l), geth(y->r)) + 1;

    return y;
}

struct node* insert(struct node* node, int k)
{
    if (node == NULL)
        return createnode(k);

    if (k < node->k)
        node->l = insert(node->l, k);
    else if (k > node->k)
        node->r = insert(node->r, k);
    else 
        return node;
    node->h = 1+ max(geth(node->l),geth(node->r));
    int balance = getbf(node);

    if (balance > 1 && k < node->l->k)
        return rRotate(node);

    if (balance < -1 && k > node->r->k)
        return lRotate(node);
    if (balance > 1 && k > node->l->k) {
        node->l = lRotate(node->l);
        return rRotate(node);
    }

    if (balance < -1 && k < node->r->k) {
        node->r = rRotate(node->r);
        return lRotate(node);
    }

    return node;
}

void inOrder(struct node* root)
{
    if (root != NULL) {
        inOrder(root->l);
        printf("%d ", root->k);
        inOrder(root->r);
    }
}

void main()
{
    struct node* root = NULL;

    int d,i,n;
    printf("Enter the root value: ");
    scanf("%d",&d);
    root = insert(root,d);
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        root=insert(root,d);
    }

    printf("Inorder traversal of AVL tree: ");
    inOrder(root);

}