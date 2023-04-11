
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack { // Stack structure
    int top;
    char arr[MAX_SIZE];
};
void initialize(struct Stack* stack){ // func to initialize stack
    stack->top = -1;
}
void push(struct Stack* stack, char element){ // push element onto stack
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->top++;
    stack->arr[stack->top] = element;
}
char pop(struct Stack* stack) { // func to pop element from stack
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char element = stack->arr[stack->top];
    stack->top--;
    return element;
}

// function to get the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^')
        return 3;
    else
        return -1;
}
// function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initialize(&stack);
    int i = 0;
    int j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
 // if the character is an operand, add it to the postfix expression
            postfix[j] = infix[i];
            j++;
        } else if (infix[i] == '(') {
// if the character is a left parenthesis, push it onto the stack
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
// if the character is a right parenthesis, pop elements from the stack and
// add them to the postfix expression until a left parenthesis is encountered
            while (stack.top != -1 && stack.arr[stack.top] != '(') {
                postfix[j] = pop(&stack);
                j++;
            }
            if (stack.top == -1) {
                printf("Invalid Expression\n");
                exit(1);
            }
            pop(&stack); // pop the left parenthesis from the stack
        } else {
// if the character is an operator, pop operators from the stack and
// add them to the postfix expression until an operator  with lower precedence is encountered
            while (stack.top != -1 && precedence(infix[i]) <= precedence(stack.arr[stack.top])) {
                postfix[j] = pop(&stack);
                j++;
            }
            push(&stack, infix[i]); // push the operator onto the stack
        }
        i++;
    }
    while (stack.top != -1) {
// pop remaining operators from the stack and add them to the postfix expression
        postfix[j] = pop(&stack);
        j++;
    }
    postfix[j] = '\0'; // add null terminator to the postfix expression
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
