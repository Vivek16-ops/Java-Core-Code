#include <stdio.h>

// Array Traversal
void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
void deletearr(int arr[], int index, int size)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int size = 5, capacity = 50, index = 3;
    int arr[50] = {1, 2, 3, 4, 5};
    traverse(arr, size);

    deletearr(arr, index, size);
    size -= 1;
    traverse(arr, size);
    return 0;
}