#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char ch;
    struct Node* next;
} node;
node* top = NULL;
int isempty() {
    if(top == NULL) return 1;
    return 0;
}
void push(char data) {
    node * newnode = (node*) malloc(sizeof(node));
    if(newnode == NULL) {
        printf("Stack Overflow!!\n");
        return;
    }
    newnode->ch = data;
    newnode->next = top;
    top = newnode;
}
char pop() {
    if(isempty()) {
        printf("Stack underflow!\n");
        return '\0';
    }
    char val = top->ch;
    top = top->next;
    return val;
}
int isBalanced(char exp[]) {
    int i;
    for(i = 0; exp[i]!='\0';i++) {
        if(exp[i] == '(') push(exp[i]);
        else if (exp[i] == ')') {
            if(isempty()) return 0;
            pop();
        }
    }
    if (isempty()) return 1;
    return 0;
}
int main() {
    char exp[100] = {'9','(','4',')','(',')'};
    int result = isBalanced(exp);
    if(result) printf("Balanced!\n");
    else printf("Not!\n");
    return 0;
}