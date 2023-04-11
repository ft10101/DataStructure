#include <stdio.h>
#include <stdlib.h>
struct Node { // define a stack data structure
    int data;
    struct Node* next;
};
struct Node* newNode(int data) { // func to create a new node
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int isEmpty(struct Node* top) { // func to check if the stack is empty
    return top == NULL;
}
// function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* node = newNode(data);
    node->next = *top;
    *top = node;
    printf("%d pushed onto the stack.\n", data);
}
// function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow.\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    printf("%d popped from the stack.\n", data);
    return data;
}
// function to print the stack
void printStack(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
// main function to test the stack operations
int main() {
    struct Node* top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);
    push(&top, 6); // this will cause stack overflow
    printStack(top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top); // this will cause stack underflow
    printStack(top);
    return 0;
}
