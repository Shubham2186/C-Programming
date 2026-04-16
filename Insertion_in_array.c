#include<stdio.h>

int main() {
    int arr[10];
    int n;
    printf("Enter  the size of array : ");
    sacnf("%d",&n);
    printf("This is taking values input in the array : \n");
    for (int i = 0;i < n;i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d",&arr[i]);
    }
    printf("This is printing the values of the array : \n");
    for (int i = 0;i < n;i++) {
        printf("%d ",arr[i]);
    }
    int pos;
    printf("Enter the position to insert an element : ");
    scanf("%d",&pos);
    for (int i = pos - 1; i < n+1; i++) {
        arr[i+1] = temp;
        arr[i+1] = arr[i];
    }
    return 0;
}