#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

// Case 1: insertion at beginning
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *p = ptr->next;
    ptr = (struct node *)malloc(sizeof(struct node));
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Case 2: Insertion at between
struct node *insertatbetween(struct node *head, int data, int index)
{
    struct node *ptr;
    struct node *p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
};

// Case 3: insert at end
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *p = ptr->next;
    ptr = (struct node *)malloc(sizeof(struct node));
    while (p != head)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

// Case 4: insertion after given node
struct node *insertafternode(struct node *head, struct node *prenode, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prenode->next;
    prenode->next = ptr;
    return head;
};

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;

    traversal(head);

    head = insertatfirst(head, 5);
    traversal(head);

    head = insertatbetween(head, 15, 2);
    traversal(head);

    head = insertatend(head, 100);
    traversal(head);

    head = insertafternode(head, third, 35);
    traversal(head);

    return 0;
}