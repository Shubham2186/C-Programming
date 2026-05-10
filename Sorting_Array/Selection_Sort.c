#include<stdio.h>
void Selection_Sort(int arr[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }       
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
int main() {
    int arr[5] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]), i;
    Selection_Sort(arr, n);
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}