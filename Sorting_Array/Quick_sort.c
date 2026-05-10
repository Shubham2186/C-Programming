#include <stdio.h>
int partition(int arr[], int low, int high)
{

    int pivot = arr[low];

    int i = low + 1;

    int j = high;

    int temp;
    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)

            i++;

        while (arr[j] > pivot)

            j--;
        if (i < j)
        {

            temp = arr[i];

            arr[i] = arr[j];

            arr[j] = temp;
        }
    }

    temp = arr[low];

    arr[low] = arr[j];

    arr[j] = temp;

    return j;
}
void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {

        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);

        quickSort(arr, p + 1, high);
    }
}
void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)

        printf("%d ", arr[i]);
}
int main()
{

    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}
