#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int n)
{
    int i, j;
    // Find the maximum element in arr
    int max = maximum(arr, n);

    // create the count array
    int *count = (int *)malloc(max + 1 * sizeof(int));

    // Initialize the array element to zero
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    // Incrememnt the corresponding element in count array
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }
    i = 0; // counter for count array
    j = 0; // counter for given array

    while (i <= max + 1)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    display(arr, n);
    countsort(arr, n);
    display(arr, n);
    return 0;
}