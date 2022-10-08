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
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
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

    inorder(p);
    return 0;
}
// In binary search tree the left node is smaller than root node and the right one is greater than root node
// Also, the inorder traversal of the binary search tree is ascending array
