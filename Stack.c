#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
    int size;
    int top;
    int *arr;
} Stack;
Stack s1;
Stack *s = &s1;
int isEmpty() {
    if(s->top == -1) {
        // printf("Stack is empty!!");
        return 1;
    }
    return 0;
}

int isFull() {
    if(s->top == s->size-1) {
        // printf("Stack is full!!");
        return 1;
    }
    return 0;
}
void push(int val) {
    if(isFull()) {
        printf("Stack Overflow!!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
    printf("Pushed %d to the satck!\n",val);
}
void pop() {
    if(isEmpty()) {
        printf("Stack underflow!!");
        return;
    }
    printf("%d\n",s->top);
    printf("%d popped out from stack!\n",s->arr[s->top]);
    s->top--;
    printf("%d\n",s->top);
}
int main() {
    int n;
    printf("ENter the size of array : ");
    scanf("%d",&n);
    s->size = n;
    s->arr = (int*)malloc(s->size*sizeof(int));
    s->top = -1;
    // s->arr[0] = 2;
    // s->top = 0;
    if(isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack is not empty!\n");
    }
    push(2);
    push(4);
    push(5);
    push(6);
    pop();
    push(7);
    push(8);
    if(isEmpty()) {
        printf("Stack is empty!");
    } else {
        printf("Stack is not empty!\n");
    }
    free(s->arr);
    return 0;
}