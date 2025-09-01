/*
 * Data Structure: Stack (Array Implementation)
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * Description: Complete implementation of stack using arrays with all basic operations
 * 
 * Operations:
 * - createStack() - Create new stack
 * - push() - Insert element (push onto stack)
 * - pop() - Remove element (pop from stack)
 * - peek() - View top element without removing
 * - isEmpty() - Check if stack is empty
 * - isFull() - Check if stack is full
 * - display() - Display stack contents
 * 
 * Features:
 * - Fixed size array implementation
 * - Complete error handling
 * - All basic stack operations
 * 
 * Usage: gcc data_structures_stack.c -o stack && ./stack
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push element onto stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", data);
        return;
    }
    stack->data[++stack->top] = data;
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop element from stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1;
    }
    int data = stack->data[stack->top--];
    printf("Popped %d from the stack\n", data);
    return data;
}

// Function to peek at top element
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Function to display stack contents
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack contents (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Function to get stack size
int getSize(struct Stack* stack) {
    return stack->top + 1;
}

int main() {
    struct Stack* stack = createStack();
    
    if (stack == NULL) {
        return 1;
    }
    
    printf("=== Stack Operations Demo ===\n");
    
    // Push elements
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    
    display(stack);
    printf("Stack size: %d\n", getSize(stack));
    
    // Peek at top element
    printf("Top element: %d\n", peek(stack));
    
    // Pop elements
    pop(stack);
    pop(stack);
    
    display(stack);
    printf("Stack size: %d\n", getSize(stack));
    
    // Try to pop from empty stack
    pop(stack);
    pop(stack);
    pop(stack);
    
    // Free memory
    free(stack);
    
    return 0;
}
