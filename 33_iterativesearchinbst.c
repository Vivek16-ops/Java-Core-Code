#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createlist(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
int main()
{
    struct node *p = createlist(5);
    struct node *p1 = createlist(3);
    struct node *p2 = createlist(6);
    struct node *p3 = createlist(1);
    struct node *p4 = createlist(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct node *n = searchIter(p,10);
    if (n != NULL)
    {
        printf("Element found: %d", n->data);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}
