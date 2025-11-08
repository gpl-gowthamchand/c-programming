# Functions in C Programming

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](07_control_flow.md) | [🏠 Home](README.md) | [➡️ Next](09_intro_to_arrays.md)

</div>

---


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

### 1. No Arguments, No Return Value

**Example:**
```c
#include <stdio.h>

void welcome() {
    printf("Welcome to C Programming, Gowtham");
}

int main() {
    welcome(); // function call
    return 0;
}
```
*Use case:* When you just want to display a message or perform an action without needing input or output.

---

### 2. With Arguments, No Return Value

**Example 1:**
```c
#include <stdio.h>

// Function with argument, no return
void welcome(char name[]) {
    printf("Hello, %s! Welcome back.\n", name);
}

int main() {
    welcome("Gowtham");
    return 0;
}
```

**Example 2:**
```c
#include <stdio.h>

void sum(int a, int b) {
    printf("%d", a + b);
}

int main() {
    sum(3, 4);
    return 0;
}
```
*Use case:* When you want to process input but don't need to return a value.

---

### 3. No Arguments, With Return Value

**Example:**
```c
#include <stdio.h>

int getAge() {
    int age;
    printf("Enter your age:: ");
    scanf("%d", &age);
    return age;
}

int main() {
    int userAge = getAge();   // capture the returned value
    printf("You are %d years old.\n", userAge);
    return 0;
}
```
*Use case:* When you want to get a value from a function but don't need to pass any input.

---

### 4. With Arguments and Return Value

**Example 1:**
```c
#include <stdio.h>

int square(int n) {
    return n * n;
}

int main() {
    int num = 6;
    int result = square(num);
    printf("Square of %d is %d\n", num, result);
    return 0;
}
```

**Example 2:**
```c
#include <stdio.h>

// Function with arguments and return value
int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 5, num2 = 7;
    int result = sum(num1, num2);  // function call
    printf("Sum of %d and %d is %d\n", num1, num2, result);
    return 0;
}
```
*Use case:* When you want to process input and get a result back.

---

## More About Functions

- **main():** The entry point of every C program is also a function.
- **void:** Used when a function does not return any value.
- **Parameters:** Variables passed to the function for processing.
- **Return Type:** Specifies the type of value the function returns (`int`, `float`, `void`, etc.).
- **Declaration (Prototype):** Should be placed before `main()` if the function is defined after `main()`.

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
/*
 * gcd_lcm_functions.c
 * Demonstrates writing and reusing functions in C.
 *
 * What it shows:
 *  - Pure functions with clear inputs/outputs
 *  - Reuse: LCM computed using GCD
 *
 * Build:  gcc gcd_lcm_functions.c -o gcd_lcm
 * Run:    ./gcd_lcm
 */

#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return (a < 0) ? -a : a; // handle negatives
}

long long lcm(int a, int b) {
    int g = gcd(a, b);
    // avoid overflow for small inputs by casting
    return (long long)a / g * b;
}

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("GCD(%d, %d) = %d\n", x, y, gcd(x, y));
    printf("LCM(%d, %d) = %lld\n", x, y, lcm(x, y));
    return 0;
}

/*
 * perfect_number_function.c
 * Checks whether a number is a perfect number using a helper function.
 *
 * What it shows:
 *  - Decomposing logic into a function (sum of proper divisors)
 *  - Simple loop + conditionals inside a function
 *
 * Build:  gcc perfect_number_function.c -o perfect
 * Run:    ./perfect
 */

#include <stdio.h>

int sumOfProperDivisors(int n) {
    if (n <= 1) return 0;
    int sum = 1; // 1 is a proper divisor for n > 1
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i; // add the paired divisor
        }
    }
    return sum;
}

int main(void) {
    int n;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (sumOfProperDivisors(n) == n)
        printf("%d is a Perfect Number\n", n);
    else
        printf("%d is NOT a Perfect Number\n", n);

    return 0;
}

/*
 * strong_number_function.c
 * Strong number: sum of factorials of digits equals the number (e.g., 145).
 *
 * What it shows:
 *  - Multiple small functions (digit factorial, checker)
 *  - Reusability of a precomputed factorial(0..9) table
 *
 * Build:  gcc strong_number_function.c -o strong
 * Run:    ./strong
 */

#include <stdio.h>

int fact[10];

void precomputeFactorials(void) {
    fact[0] = 1;
    for (int d = 1; d <= 9; d++) fact[d] = fact[d - 1] * d;
}

int isStrong(int n) {
    int original = n, sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += fact[digit];
        n /= 10;
    }
    return sum == original;
}

int main(void) {
    precomputeFactorials();

    int n;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isStrong(n))
        printf("%d is a Strong Number\n", n);
    else
        printf("%d is NOT a Strong Number\n", n);

    return 0;
}


## Summary

- Functions make code modular, reusable, and easier to maintain.
- Always declare functions before using them (or define them above `main()`).
- Choose the right function type based on whether you need arguments and/or a return value.
- Use functions to organize logic, avoid repetition, and improve code clarity.

---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](07_control_flow.md) | [🏠 Home](README.md) | [➡️ Next](09_intro_to_arrays.md)

</div>