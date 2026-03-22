#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} Node;
Node * top = NULL;
int isEmpty() {
    if(top == NULL) {
        printf("Satck is empty!\n");
        return 1;
    }
    return 0;
}
// int isFull() {
//     Node* Newnode = (Node*)malloc(sizeof(Node));
//     if (Newnode == NULL) {
//         printf("Stack Overflow!\nNode is unable to be created!\n");
//         return 1;
//     }
//     return 0;
// }
void push(int val) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if(NewNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    NewNode->data = val;
    NewNode->next = top;
    top = NewNode;
}
int pop() {
    if(isEmpty()) {
        printf("Stack Underflow!!\n");
        return -1;
    }
    Node* temp = top;
    top = top->next;
    int val = temp->data;
    free(temp);
    return val;
}
void traversal() {
    Node* temp = top;
    while(temp!=NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int peek(int pos) {
    Node* temp = top;
    int i = 0;
    while(i<pos - 1 && temp!= NULL){
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range of stack!\n");
        return -1; 
    }
    return temp->data;
}
int stackTop() {
    return top->data;
}
int stackBottom() {
    Node* temp = top;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    int val = temp->data;
    free(temp);
    return val;
}
int main() {
    pop();
    push(5);
    push(6);
    push(7);
    printf("%d popped from stack.\n",pop());
    push(8);
    push(9);
    printf("%d popped from stack.\n",pop());
    push(10);
    printf("element at position %d is %d.\n",2,peek(2));
    printf("element at position %d is %d.\n",3,peek(3));
    printf("element at position %d is %d.\n",4,peek(4));
    printf("Bottommost element of stack is %d.\n ",stackBottom());
    printf("Topmost element of stack is %d.\n ",stackTop());
    // iBegin(6);
    traversal();
    return 0;
}