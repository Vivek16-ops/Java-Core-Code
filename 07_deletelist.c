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

// Case 1: Deletion at beginning
struct node *deletionatfirst(struct node *head)
{
    struct node *q;
    q = head;
    head = head->next;
    free(q);
    return head;
}

// Case 2: deletion at between
struct node *deletionatbetween(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = p->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);

    return head;
}

// Case 3: deletion at end
struct node *deleteatend(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 4: deletion after a given value
struct node *deleteaftervalue(struct node *head, int value)
{
    struct node *ptr = head;
    struct node *q = ptr->next;
    while (q->data != value && q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fifth;
    struct node *sixth;
    struct node *seventh;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fifth;

    fifth->data = 40;
    fifth->next = sixth;

    sixth->data = 50;
    sixth->next = seventh;

    seventh->data = 60;
    seventh->next = NULL;

    traversal(head);

    // head = deletionatfirst(head);
    // traversal(head);

    // head = deletionatbetween(head, 2);
    // traversal(head);

    // head = deleteatend(head);
    // traversal(head);

    head = deleteaftervalue(head, 30);
    traversal(head);

    return 0;
}