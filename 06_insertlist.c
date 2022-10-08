#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// case 1: Insertion at first
struct node *insertionatfirst(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Case 2: Insertion at between
struct node *insertionatbetween(struct node *head, int data, int index)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3: Insertion at end
struct node *insertionatend(struct node *head, int data)
{
    struct node *p;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// case 4: Insert after node
struct node *insertafternode(struct node *head, struct node *prenode, int data)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prenode->next;
    prenode->next = ptr;

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    traversal(head);

    head = insertionatfirst(head, 5);
    traversal(head);

    head = insertionatbetween(head, 15, 2);
    traversal(head);

    head = insertionatend(head, 40);
    traversal(head);

    head = insertafternode(head, third ,35);
    traversal(head);

    return 0;
}