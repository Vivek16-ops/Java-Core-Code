#include <stdio.h>

// Array Traversal
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

// Code for Insertion
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int size = 5, element = 45, capacity = 50, index = 3;
    int arr[50] = {1, 3, 78, 90, 100};
    display(arr, size);
    indInsertion(arr, size, element, capacity, index);
    size += 1;
    display(arr, size);
}