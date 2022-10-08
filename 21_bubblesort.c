#include <stdio.h>
#include <stdlib.h>

// Array Traversal
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
void bubblesort(int arr[], int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++) // for number of pass
    {
        printf("Workig on pass no: %d\n", i+1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // for comparision in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}

int main()
{
    // int arr[] = {12,54,65,7,23,9};
    int arr[] = {1, 5, 6, 7, 23, 90};
    int size = 6;
    display(arr, size);    // printing the array before sorting
    bubblesort(arr, size); // Function to sort the array
    display(arr, size);    // printing the array after sorting
}