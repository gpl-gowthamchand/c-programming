# Functions in C Programming

Functions are blocks of code designed to perform a specific task.  
They help organize code, promote reusability, and make programs easier to read and maintain.

## Why Use Functions?

- **Modularity:** Breaks a large program into smaller, manageable pieces.
- **Reusability:** Allows code to be reused in different parts of the program.
- **Readability:** Makes code easier to understand.
- **Debugging:** Easier to test and debug individual parts.

---

## What is a Function?

A function in C consists of:
- **Declaration (Prototype):** Tells the compiler about the function's name, return type, and parameters.
- **Definition:** Contains the actual code to be executed.
- **Call:** Invokes the function to perform its task.

---

## Function Syntax

**Declaration (Prototype):**
```c
return_type function_name(parameter_list);
```

**Definition:**
```c
return_type function_name(parameter_list) {
    // function body
}
```

**Call:**
```c
function_name(arguments);
```

---

## Types of Functions (Based on Arguments and Return Type)

There are 4 main types:

1. **No arguments, no return value**
   ```c
   void greet() {
       printf("Hello!\n");
   }
   // Call
   greet();
   ```

2. **Arguments, no return value**
   ```c
   void printSum(int a, int b) {
       printf("Sum: %d\n", a + b);
   }
   // Call
   printSum(3, 5);
   ```

3. **No arguments, return value**
   ```c
   int getNumber() {
       return 42;
   }
   // Call
   int num = getNumber();
   ```

4. **Arguments and return value**
   ```c
   int add(int x, int y) {
       return x + y;
   }
   // Call
   int result = add(4, 7);
   ```

---

## Example: Declaration, Definition, and Call

```c
#include <stdio.h>

// Declaration (prototype)
int multiply(int, int);

int main() {
    int a = 5, b = 6;
    int product = multiply(a, b); // Function call
    printf("Product: %d\n", product);
    return 0;
}

// Definition
int multiply(int x, int y) {
    return x * y;
}
```

---

## Notes

- **Return Type:** Specifies the type of value the function returns (`int`, `float`, `void`, etc.).
- **Parameters:** Variables passed to the function for processing.
- **void:** Used when a function does not return any value.
- **main():** The entry point of every C program is also a function.

---

## Summary

- Functions make code modular, reusable, and easier to maintain.
- Always declare functions before using them (or define them above `main()`).
- Choose the right function type based on whether you need arguments and/or a return