#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueueR(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full !\n");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}
void enqueueF(struct queue *q, int val)
{

    q->f = q->f - 1;
    q->arr[q->f] = val;
}
int dequueF(struct queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty: ");
        return val;
    }
    else
    {
        q->f = q->f + 1;
        val = q->arr[q->f];
        return val;
    }
}
int dequueR(struct queue *q)
{
    q->r = q->r - 1;
    int val = q->arr[q->r];
    return val;
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueR(q, 12);
    enqueueR(q, 45);
    enqueueR(q, 78);
    enqueueR(q, 56);
    enqueueR(q, 58);
    enqueueR(q, 23);
    enqueueR(q, 98);
    enqueueR(q, 10);
    enqueueR(q, 54);
    enqueueR(q, 11);

    if (isEmpty(q))
    {
        printf("Queue is now empty\n");
    }
    else
    {
        printf("There is some element in queue\n");
    }

    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));
    printf("dequing element: %d\n ", dequueF(q));

    if (isEmpty(q))
    {
        printf("Queue is now empty\n");
    }
    else
    {
        printf("There is some element in queue\n");
    }

    enqueueF(q, 11);
    enqueueF(q, 12);
    enqueueF(q, 13);
    if (isEmpty(q))
    {
        printf("Queue is now empty\n");
    }
    else
    {
        printf("There is some element in queue\n");
    }
    printf("dequing element: %d\n ", dequueR(q));
    return 0;
}