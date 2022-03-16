// implement merge sort
#include <stdio.h>
#include <malloc.h>

void mergeAndSort(int arr[], int start, int mid, int end)
{
    int *temp;
    temp = (int *)malloc((end - start + 1) * sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i <= mid)
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= end)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    k = 0;
    for (int x = start; x <= end; x++)
    {
        arr[x] = temp[k];
        k++;
    }
    return;
}

void mergeSort(int arr[], int first, int last)
{
    int mid;
    if (first < last)
    {
        mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        mergeAndSort(arr, first, mid, last);
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

    mergeSort(arr, 0, size - 1);

    printf("Sorted Array: ");
    printArray(arr, size);
    return;
}
