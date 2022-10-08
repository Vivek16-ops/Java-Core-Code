#include <stdio.h>
#include <stdlib.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
void insertionsort(int arr[], int n)
{
    int j, key;
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[5] = {7, 2, 91, 77, 3};
    int n = 5;
    printarray(arr, n);
    insertionsort(arr, n);
    printarray(arr, n);
    return 0;
}