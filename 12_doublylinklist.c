#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *insertatempty(int data)
{
    struct node *ptr;
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
struct node *insertatend(struct node *head ,int data)
{
    struct node *p=head;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data=data;
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    return head;
};
struct node *createlist(struct node *head)
{
    int i, data, n;
    printf("Enter the number of node: ");
    scanf("%d", &n);

    if (n == 0)
    {
        return head;
    }

    printf("Enter the element 1: ");
    scanf("%d", &data);
    head = insertatempty(data);

    for (i = 1; i < n; i++)
    {
        printf("Enter the elemene %d :", i + 1);
        scanf("%d", &data);
        head = insertatend(head , data);
    }
    return head;
};
void traversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
       printf(" %d ",ptr->data);
       ptr=ptr->next;
    }
    printf("\n");
}
void oppotraversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
       printf(" %d ",ptr->data);
       ptr=ptr->prev;
    }
    printf("\n");
}
int main()
{
    struct node *head = NULL;
    head = createlist(head);
    traversal(head);
    oppotraversal(head);
    return 0;
}