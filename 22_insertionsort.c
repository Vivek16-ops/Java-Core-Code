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
    int key, j;
    for (int i = 1; i <= n - 1; i++) // for number of passes
    {
        key = arr[i]; // element to be inserted
        j = i - 1;
        // Loop for each pass
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

    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printarray(arr, n);
    insertionsort(arr, n);
    printarray(arr, n);
    return 0;
}