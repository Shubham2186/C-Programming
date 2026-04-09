#include<stdio.h>
int main() {
    int arr[10] = {1,2,3,4,34,45,56,78,89,100};
    int key;
    printf("Enter element to search : ");
    scanf("%d",&key);
    int i, ispresent = 0,index;
    int count = sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i< count; i++) {
        if(arr[i] == key) {
            index = i;
            ispresent = 1;
            break;
        }
    }
    if(ispresent) printf("Element present in the array at %d position.\n",index+1);
    else printf("Element is not present in the array!\n");
    return 0;
}