#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f; // to store front index value
    int r; // to store back index value
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
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow! cannot push element %d\n", val);
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        q->f = q->f + 1;
        int x = q->arr[q->f];
        return x;
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(sizeof(struct queue));

    enqueue(q, 12);
    enqueue(q, 45);
    enqueue(q, 75);
    enqueue(q, 89);
    enqueue(q, 54);

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Some element is inserted in your Queue\n");
    }
    printf("Dequeuing element is:%d\n", dequeue(q));

    return 0;
}
// There are some drawbacks of queue
// Space is not used efficiently
