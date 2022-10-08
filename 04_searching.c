#include <stdio.h>
#include <stdlib.h>

// linear search code
int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// Binary search Code
int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (mid < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // int arr[] = {23, 675, 2, 3, 9, 76, 4, 5, 78, 21, 45, 23, 65};
    // int size = sizeof(arr) / sizeof(int);
    // int element = 4;
    // int searchindex = linearsearch(arr, size, element);
    // printf("The element %d was found at index %d \n", element, searchindex);

    int arr1[] = {1, 2, 3, 45, 6, 7, 8, 9, 10, 11, 12, 34, 56, 78, 90};
    int size1 = sizeof(arr1) / sizeof(int);
    int element1 = 12;
    int searchindex1 = binarysearch(arr1, size1, element1);
    printf("The element %d was found at index %d \n", element1, searchindex1);

    return 0;
}