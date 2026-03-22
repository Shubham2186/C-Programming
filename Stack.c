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
    printf("Pushed %d to the satck!\n",val); // no need to do this, avoid
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
int main() {
    s = (Stack*)malloc(sizeof(Stack));
    int n;
    printf("Enter the size of array : ");
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
    printf("%d popped from stack!\n",pop());
    push(7);
    push(8);
    push(9);
    printf("%d\n",peek(3));
    if(isEmpty()) {
        printf("Stack is empty!");
    } else {
        printf("Stack is not empty!\n");
    }
    free(s->arr);
    return 0;
}