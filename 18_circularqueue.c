#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isfull(struct queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
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
    if (isfull(q))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
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
        q->f = (q->f + 1) % q->size;
        int val = q->arr[q->f];
        return val;
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 43);
    enqueue(q, 45);
    enqueue(q, 89);
    enqueue(q, 78);
    enqueue(q, 63);
    if (isEmpty(q))
    {
        printf("Queue is now empty");
    }
    else
    {
        printf("There is some element in your queue\n");
    }

    printf("Dequing element is:%d\n", dequeue(q));
    return 0;
}
// circular increment
// i= (i+1)%size