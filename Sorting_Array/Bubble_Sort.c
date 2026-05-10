#include<stdio.h>
void Bubble_Sort(int arr[], int n) {
    int i,j,temp;
    int swapped;
    for (i = 0;i<n-1;i++) {
        swapped = 0;
        for (j = 0; j< n-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
int main() {
    int arr[10] = {2,7,12,24,4,56,71,100,204,1};
    int count = sizeof(arr)/sizeof(arr[0]), i;
    printf("Unsorted array : \n");
    for (i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSorted array : \n");
    Bubble_Sort(arr,count);
    for (i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}