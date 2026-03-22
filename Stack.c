#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
    int size;
    int top;
    int *arr;
} Stack;
Stack *s;
int isEmpty() {
    if(s->top == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(s->top == s->size-1) {
        return 1;
    }
    return 0;
}
void push(int val) {
    if(isFull()) {
        printf("Stack Overflow!!\nCannot push %d to stack.\n",val);
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}
int pop() {
    if(isEmpty()) {
        printf("Stack underflow!!\n");
        return -1;
    }
    int val = s->arr[s->top]; 
    s->top--;
    return val;
}
int peek(int pos) {
    int d = s->top - pos + 1;
    if(d<0) {
        printf("Invalid Position!!\n");
        return -1;
    }
    return s->arr[d];
}
void stackTop() {
    if(isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d is the topmost element.\n",s->arr[s->top]);
} 
void stackBottom() {
    if(isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d is the topmost element.\n",s->arr[0]);
}
int main() {
    s = (Stack*)malloc(sizeof(Stack));
    int n,pos;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter the position of whose element you want to find : ");
    scanf("%d",&pos);
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
    printf("%d popped from stack!\n",pop());
    push(7);
    push(8);
    push(9);
    printf("The value at position %d is %d.\n",pos, peek(pos));
    free(s->arr);
    return 0;
}