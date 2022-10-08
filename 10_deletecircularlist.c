#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertatempty(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = ptr;
    return ptr;
}
struct node *insertatend(struct node *head, int data)
{
    struct node *p = head;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    do
    {
        p = p->next;
    } while (p->next != head);
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node *createlist(struct node *head)
{
    int i, data, n;

    printf("Enter the number of Node: ");
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
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        head = insertatend(head, data);
    }
    return head;
}
void traversal(struct node *head)
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty");
    }
    do
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
int main()
{
    struct node *head = NULL;
    head = createlist(head);
    traversal(head);
     
    head = deletionatfirst(head);
    traversal(head);

    return 0;
}