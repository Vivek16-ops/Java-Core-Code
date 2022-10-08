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
void seletionsort(int arr[], int n)
{
    int indexofMin ,temp;
    printf("Running selection sort...\n");
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        indexofMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexofMin])
            {
                indexofMin = j;
            }
        }
        temp = arr[i];
        arr[i]=arr[indexofMin];
        arr[indexofMin]=temp;
    }
}
int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printarray(arr, n);
    seletionsort(arr, n);
    printarray(arr, n);
    return 0;
}