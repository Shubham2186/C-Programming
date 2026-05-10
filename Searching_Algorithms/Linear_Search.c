#include<stdio.h>
int linear_search(int arr[],int key, int n){
    int i;
    for(i = 0;i<n;i++) {
        if(arr[i] == key) {
        return 1;
        }
    }
    return 0;
}
int main() {
    int arr[10] = {1,2,3,4,34,45,56,78,89,100};
    int key;
    printf("Enter element to search : ");
    scanf("%d",&key);
    int count = sizeof(arr)/sizeof(arr[0]);
    if(linear_search(arr,key,count)) printf("Element present \n");
    else printf("Element is not present in the array!\n");
    return 0;
}