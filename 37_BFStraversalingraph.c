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
    if (q->r == q->f)
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
void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue Overfloe\n");
    }
    q->r++;
    q->arr[q->r] = data;
}
int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    q->f++;
    int val = q->arr[q->f];
    return val;
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 500;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // BFS Implementation
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf(" %d ", i);
    visited[i] = 1;
    enqueue(q, i);
    while (!isEmpty(q))
    {
        node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf(" %d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    return 0;
}