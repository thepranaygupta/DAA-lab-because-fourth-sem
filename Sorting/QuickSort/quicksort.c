#include <stdio.h>
#include <malloc.h>

void quickSort(int arr[], int first, int last)
{
    int temp;
    int low = first;
    int high = last;
    int pivot = arr[(low + high) / 2];
    while (low < high)
    {
        while (arr[low] < pivot)
        {
            low++;
        }
        while (arr[high] > pivot)
        {
            high--;
        }
        if (low <= high)
        {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    if (low < last)
    {
        quickSort(arr, low, last);
    }
    if (high > first)
    {
        quickSort(arr, first, high);
    }
    return;
}

void printArray(int arr[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Unsorted Array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted Array: ");
    printArray(arr, size);
}
