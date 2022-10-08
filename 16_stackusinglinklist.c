#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *top)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *top, int data) // Inserting node at index zero
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (isFull(top))
    {
        printf("Stack Overflow! Cannot push element\n");
    }
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    return top;
};
int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    struct node *n = *top;
    int x = n->data;
    *top = (*top)->next;
    free(n);
    return x;
}
void traversal(struct node *top)
{
    while (top != NULL)
    {
        printf("Element is: %d\n", top->data);
        top = top->next;
    }
}
int main()
{
    struct node *top = NULL;
    top = push(top, 23);
    top = push(top, 13);
    top = push(top, 43);
    traversal(top);

    int element = pop(&top);
    printf("Popped element is :%d\n", element);
    traversal(top);
    return 0;
}