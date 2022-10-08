#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

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
void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full! Cannot push element %d in queue\n", val);
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty: ");
        return val;
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}
int main()
{
    printf("%d\n", dequeue());
    enqueue(12);
    enqueue(45);
    enqueue(89);
    enqueue(52);
    enqueue(25);
    enqueue(74);
    traversal(f);

    printf("Dequing element is:%d\n", dequeue());

    return 0;
}