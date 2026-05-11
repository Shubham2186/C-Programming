#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node* next;
} Node;
Node * top = NULL;
int isEmpty() {
    if(top == NULL) {
        // printf("Satck is empty!\n");
        return 1;
    }
    return 0;
}
int isFull() {
    Node* Newnode = (Node*)malloc(sizeof(Node));
    if (Newnode == NULL) {
        // printf("Stack Overflow!\nNode is unable to be created!\n");
        free(Newnode);
        return 1;
    }
    return 0;
}
void push(char val) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if(NewNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    NewNode->data = val;
    NewNode->next = top;
    top = NewNode;
}
char pop() {
    if(isEmpty()) {
        // printf("Stack Underflow!!\n");
        return -1;
    }
    Node* temp = top;
    top = top->next;
    char val = temp->data;
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
    if(top == NULL) return 0;
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
int isoperator(char exp) {
    
    if(exp == '+' || exp == '-' || exp == '*' || exp == '/' || exp == '^') return 1;
    return 0;
}
int prec(char exp) {
    if(exp == '+' || exp == '-') return 1;
    if(exp == '*' || exp == '/') return 2;
    if(exp == '^') return 3;
    return -1;
}
void Infix_to_postfix(char *infix, char *postfix) {
    int i = 0, j = 0;

    while(infix[i] != '\0') {

        if(infix[i] == '(') {
            push(infix[i]);
            i++;
        }

        else if(infix[i] == ')') {
            while(!isEmpty() && stackTop() != '(') {
                postfix[j++] = pop();
            }
            pop();
            i++;
        }

        else if(!isoperator(infix[i])) {
            postfix[j++] = infix[i++];
        }

        else {
            while(!isEmpty() &&
                  stackTop() != '(' &&
                  prec(stackTop()) >= prec(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
            i++;
        }
    }

    while(!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}
int main() {
    char infix[] = "a+b*4-2";
    char postfix[100];
    Infix_to_postfix(infix, postfix);
    printf("%s",postfix);
    return 0;
}