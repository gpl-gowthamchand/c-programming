/*
 * Tutorial: Functions in C Programming
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Description: A comprehensive tutorial on functions in C programming
 * 
 * Prerequisites: Basic understanding of variables and data types in C
 * 
 * Learning Objectives:
 * - Understand function declaration and definition
 * - Learn about function parameters and return values
 * - Master different types of function calls
 * - Understand scope and lifetime of variables
 * - Learn about recursion and its applications
 * 
 * Step 1: Basic Function Concepts
 * [Code for step 1]
 * 
 * Step 2: Function Parameters and Return Values
 * [Code for step 2]
 * 
 * Step 3: Function Overloading and Variadic Functions
 * [Code for step 3]
 * 
 * Step 4: Recursion
 * [Code for step 4]
 * 
 * Practice Exercise:
 * Create a function that calculates the factorial of a number using recursion
 * 
 * Common Mistakes:
 * - Forgetting to declare functions before use
 * - Mismatching parameter types
 * - Not handling return values properly
 */

#include <stdio.h>
#include <stdarg.h>

// Function declarations (prototypes)
void greetUser();
int add(int a, int b);
float calculateArea(float length, float width);
void printNumbers(int start, int end);
int factorial(int n);
int fibonacci(int n);
void demonstrateScope();
int sum(int count, ...);

// Step 1: Basic Function Concepts
void basicFunctions() {
    printf("=== Step 1: Basic Function Concepts ===\n");
    
    greetUser();
    
    int result = add(10, 20);
    printf("10 + 20 = %d\n", result);
    
    float area = calculateArea(5.5, 3.2);
    printf("Area of rectangle (5.5 x 3.2) = %.2f\n", area);
}

// Function definition - no parameters, no return value
void greetUser() {
    printf("Hello! Welcome to the Functions Tutorial! 👋\n");
}

// Function definition - with parameters and return value
int add(int a, int b) {
    return a + b;
}

// Function definition - with float parameters and return value
float calculateArea(float length, float width) {
    return length * width;
}

// Step 2: Function Parameters and Return Values
void functionParameters() {
    printf("\n=== Step 2: Function Parameters and Return Values ===\n");
    
    // Different ways to call functions
    int x = 15, y = 25;
    
    // Direct function call
    printf("Direct call: %d + %d = %d\n", x, y, add(x, y));
    
    // Function call with expressions
    printf("Expression call: %d + %d = %d\n", x, y, add(x * 2, y / 5));
    
    // Function call with constants
    printf("Constant call: 100 + 200 = %d\n", add(100, 200));
    
    // Function with no return value
    printf("Printing numbers from 1 to 5:\n");
    printNumbers(1, 5);
}

// Function with no return value
void printNumbers(int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Step 3: Recursion
void recursionExamples() {
    printf("\n=== Step 3: Recursion Examples ===\n");
    
    int num = 5;
    printf("Factorial of %d = %d\n", num, factorial(num));
    
    printf("Fibonacci sequence (first 10 numbers):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Recursive function to calculate factorial
int factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Step 4: Variable Scope and Lifetime
void demonstrateScope() {
    printf("\n=== Step 4: Variable Scope and Lifetime ===\n");
    
    int global_var = 100;  // Local to this function
    
    printf("Global variable in function: %d\n", global_var);
    
    // Block scope
    {
        int block_var = 200;
        printf("Block variable: %d\n", block_var);
        printf("Global variable in block: %d\n", global_var);
    }
    
    // block_var is not accessible here
    // printf("Block variable outside block: %d\n", block_var); // Error!
    
    printf("Global variable after block: %d\n", global_var);
}

// Step 5: Variadic Functions (Variable Arguments)
void variadicFunctions() {
    printf("\n=== Step 5: Variadic Functions ===\n");
    
    printf("Sum of 3 numbers (10, 20, 30): %d\n", sum(3, 10, 20, 30));
    printf("Sum of 5 numbers (1, 2, 3, 4, 5): %d\n", sum(5, 1, 2, 3, 4, 5));
    printf("Sum of 2 numbers (100, 200): %d\n", sum(2, 100, 200));
}

// Variadic function to sum variable number of integers
int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

// Practice Exercise Solution
void practiceExercise() {
    printf("\n=== Practice Exercise: Factorial Function ===\n");
    
    int number;
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &number);
    
    if (number < 0) {
        printf("Factorial is not defined for negative numbers!\n");
    } else {
        printf("Factorial of %d = %d\n", number, factorial(number));
    }
    
    printf("Exercise completed! ✅\n");
}

// Common Mistakes Demonstration
void commonMistakes() {
    printf("\n=== Common Mistakes to Avoid ===\n");
    
    printf("1. Function Declaration:\n");
    printf("   Always declare functions before use or define them before main()\n");
    
    printf("2. Parameter Types:\n");
    printf("   Make sure parameter types match in declaration and definition\n");
    
    printf("3. Return Values:\n");
    printf("   Don't forget to handle return values when needed\n");
    
    printf("4. Recursion Base Cases:\n");
    printf("   Always have proper base cases in recursive functions\n");
    
    printf("5. Variable Scope:\n");
    printf("   Understand where variables are accessible\n");
}

// Function to demonstrate function pointers
void functionPointers() {
    printf("\n=== Bonus: Function Pointers ===\n");
    
    // Function pointer declaration
    int (*operation)(int, int);
    
    // Assign function to pointer
    operation = add;
    
    printf("Using function pointer: %d + %d = %d\n", 15, 25, operation(15, 25));
    
    // Function pointer array
    int (*operations[])(int, int) = {add, add}; // Can add more operations
    
    printf("Using function pointer array: %d + %d = %d\n", 10, 20, operations[0](10, 20));
}

int main() {
    printf("========================================\n");
    printf("    Functions Tutorial in C Programming \n");
    printf("========================================\n");
    
    basicFunctions();
    functionParameters();
    recursionExamples();
    demonstrateScope();
    variadicFunctions();
    practiceExercise();
    commonMistakes();
    functionPointers();
    
    printf("\n========================================\n");
    printf("    Tutorial Complete! 🎉\n");
    printf("========================================\n");
    printf("Key Takeaways:\n");
    printf("- Functions help organize and reuse code\n");
    printf("- Always declare functions before use\n");
    printf("- Understand parameter passing mechanisms\n");
    printf("- Use recursion carefully with proper base cases\n");
    printf("- Be aware of variable scope and lifetime\n");
    
    return 0;
}
