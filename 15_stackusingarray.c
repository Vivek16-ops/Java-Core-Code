
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push the %d in the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop the element\n");
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int peek(struct stack *ptr, int i)
{
    int arrint = ptr->top - i + 1; // learn
    if (arrint < 0)
    {
        printf("Invalid Position\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrint];
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->size-1];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack is successfully created\n");

    printf("Before Pushing Stack is  Empty %d\n", isEmpty(s));
    printf("Before Pushing stack is full %d\n", isFull(s));

    push(s, 45);
    push(s, 23);
    push(s, 56);
    push(s, 67);
    push(s, 19);
    push(s, 78);
    push(s, 98);
    push(s, 34);
    push(s, 90);
    push(s, 76); // stack maximum size reached
    // push(s, 40); // This will show stack overflow

    printf("After Pushing Stack is Empty %d\n", isEmpty(s));
    printf("After Pushing the stack is full %d\n", isFull(s));

    printf(" %d ",pop(s));
    printf("After Poping\n");
    printf("After Poping Stack is Empty %d\n", isEmpty(s));
    printf("After Poping stack is full %d\n", isFull(s));

    for (int j = 0; j <= s->size - 1; j++) // learn
    {
        printf(" %d\n ", peek(s, j));
    }

    printf("The Top Element in the stack is %d\n", stackTop(s));
    printf("The Bottom Element in the stack is %d\n", stackBottom(s));

    return 0;
}