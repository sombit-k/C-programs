
#include <stdio.h>
#include <stdlib.h>

struct node {
    int k;
    struct node *l, *r;
};

struct node* newNodeCreate(int v)
{
    struct node* temp
        = (struct node*)malloc(
            sizeof(struct node));
    temp->k = v;
    temp->l = temp->r = NULL;
    return temp;
}

struct node*
searchNode(struct node* root, int t)
{
    if (root == NULL || root->k == t) {
        return root;
    }
    if (root->k < t) {
        return searchNode(root->r, t);
    }
    return searchNode(root->l, t);
}
struct node*
insertNode(struct node* node, int v)
{
    if (node == NULL) {
        return newNodeCreate(v);
    }
    if (v < node->k) {
        node->l = insertNode(node->l, v);
    }
    else if (v > node->k) {
        node->r = insertNode(node->r, v);
    }
    return node;
}

void inOrder(struct node* root)
{
    if (root != NULL) {
        inOrder(root->l);
        printf(" %d ", root->k);
        inOrder(root->r);
    }
}
struct node* findMin(struct node* root)
{
    if (root == NULL) {
        return NULL;
    }
    else if (root->l != NULL) {
        return findMin(root->r);
    }
    return root;
}
struct node* delete (struct node* root,int x)
{
    if (root == NULL)
        return NULL;

    if (x > root->k) {
        root->r = delete (root->r, x);
    }
    else if (x < root->k) {
        root->l = delete (root->l, x);
    }
    else {
        if (root->l == NULL && root->r == NULL) {
            free(root);
            return NULL;
        }
        else if (root->l == NULL
                 || root->r == NULL) {
            struct node* temp;
            if (root->l == NULL) {
                temp = root->r;
            }
            else {
                temp = root->l;
            }
            free(root);
            return temp;
        }
        else {
            struct node* temp
                = findMin(root->r);
            root->k = temp->k;
            root->r = delete (root->r, temp->k);
        }
    }
    return root;
}

void main()
{
    int d,c;
    struct node* root = NULL;
    printf("Enter root value: ");
    scanf("%d",&d);
    root = insertNode(root, d);
    printf("1)Insert 2)Delete 3)Search 4)Display 5)Exit");
    while(1)
    {
        printf("\nChoice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("Insert value: ");
                    scanf("%d",&d);
                    insertNode(root,d);
                    break;
            case 2: printf("Delete value: ");
                    scanf("%d",&d);
                    struct node* temp = delete (root, d);
                    printf("%d deleted",temp->k);
                    free(temp);
                    break;
            case 3: printf("Search for: ");
                    scanf("%d",&d);
                    if(searchNode(root, d))
                        printf("Node found");
                    else printf("Not found");break;
            case 4: inOrder(root);printf("\n");
                    break;
            case 5: return;



        }
    }
}

