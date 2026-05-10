#include<stdio.h>
int Binary_Search(int key, int n, int arr[]) {
    int u = n-1;
    int l = 0;
    int mid;
    while (l<=u) {
        mid = (l+u)/2;
        if (key == arr[mid]) return 1;
        else if (key>arr[mid]) {
            l = mid+1;
        } else {
            u = mid-1;
        }
    }
    return 0;
}
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int key, count = sizeof(arr)/sizeof(arr[0]);

    printf("Enter element to search : ");
    scanf("%d",&key);
    if(Binary_Search(key,count,arr)) {
        printf("Element present!\n");
    } else {
        printf("Element is not present!");
    }
    return 0;
}