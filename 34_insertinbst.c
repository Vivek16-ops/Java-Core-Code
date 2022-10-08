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
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return;
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
    struct node* new1 = createlist(key);
    if (key < prev->data)
    {
        prev->left = new1;
    }
    else
    {
        prev->right = new1;
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

    insert(p, 7);
    inorder(p);
    return 0;
}
