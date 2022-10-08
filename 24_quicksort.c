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
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    { 
        int partionindex; // Index of pivot after partition
        partionindex = partition(arr, low, high);
        quicksort(arr, low, partionindex - 1);  // sorting left subarray
        quicksort(arr, partionindex + 1, high); // sorting right subarray
    }
}
int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printarray(arr, n);
    quicksort(arr, 0, n - 1);
    printarray(arr, n);
    return 0;
}