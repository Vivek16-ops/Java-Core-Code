#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}
struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;

    return n;
};
int max(int a, int b)
{
    return a > b ? a : b;
}
int getbalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return x;
}
struct node *insert(struct node *node, int key)
{

    if (node == NULL)
    {
        return createnode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);
        return node;
    }
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getbalancefactor(node);

    // Now there is possiblity that the above node goes in imbalance state

    // so the following cases can applied

    // left-left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }

    // right-right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }

    // left-right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // Right-left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 45);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 9);
    preorder(root);

    return 0;
}