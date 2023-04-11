
#include <stdio.h>
#include <stdlib.h>
// define a stack data structure
struct Stack {
    int top;
    int capacity;
    int* array;
};
// function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(capacity * sizeof(int));
    return stack;
}
// function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
// function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
// function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow.\n");
        return;
    }
    stack->array[++stack->top] = data;
    printf("%d pushed onto the stack.\n", data);
}
int pop(struct Stack* stack) { //pop an element from the stack
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        return -1; }
    int data = stack->array[stack->top--];
    printf("%d popped from the stack.\n", data);
    return data;
}
void printStack(struct Stack* stack) { // function to print the stack
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;  }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]); }
    printf("\n");
}
int main() { // main function to test the stack operations
    struct Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6); // this will cause stack overflow
    printStack(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack); // this will cause stack underflow
    printStack(stack);
    return 0;
}
