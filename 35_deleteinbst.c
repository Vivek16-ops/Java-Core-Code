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
struct node *inordePredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletenode(struct node *root, int val)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    // leaf node
    if (root->left == NULL || root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // Search the node to be deleted
    if (val < root->data)
    {
        deletenode(root->left, val);
    }
    else if (val > root->data)
    {
        deletenode(root->right, val);
    }
    // Deletion Strategy when  the node is found
    else
    {
        ipre = inordePredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
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

    deletenode(p, 3);
    inorder(p);
    return 0;
}
