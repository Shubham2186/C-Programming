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
    node* temp =top;
    char val = top->ch;
    top = top->next;
    free(temp);
    return val;
}
int isBalanced(char exp[]) {
    int i;
    for(i = 0; exp[i]!='\0';i++) {
        if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')) push(exp[i]);
        else if (exp[i] == ')') {
            if(isempty()) return 0;
            if(top->ch == '(') pop();
            else return 0;
        }
        else if (exp[i] == '}') {
            if(isempty()) return 0;
            if(top->ch == '{') pop();
            else return 0;
        }
        else if (exp[i] == ']') {
            if(isempty()) return 0;
            if(top->ch == '[') pop();
            else return 0;
        }
    }
    if (isempty()) return 1;
    return 0;
}
int main() {
    char exp[] = "({[({)}]})";
    int result = isBalanced(exp);
    if(result) printf("Balanced!\n");
    else printf("Not!\n");
    return 0;
}