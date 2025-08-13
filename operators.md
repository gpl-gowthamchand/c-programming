# Operators in C Programming

Operators are special symbols that perform operations on variables and values.  
They are essential for manipulating data and controlling program flow.

## Types of Operators

### 1. Arithmetic Operators
Used for mathematical calculations.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `+`      | Addition         | `a + b`        |
| `-`      | Subtraction      | `a - b`        |
| `*`      | Multiplication   | `a * b`        |
| `/`      | Division         | `a / b`        |
| `%`      | Modulus (remainder) | `a % b`    |

### 2. Relational Operators
Used to compare values.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `==`     | Equal to         | `a == b`       |
| `!=`     | Not equal to     | `a != b`       |
| `>`      | Greater than     | `a > b`        |
| `<`      | Less than        | `a < b`        |
| `>=`     | Greater or equal | `a >= b`       |
| `<=`     | Less or equal    | `a <= b`       |

### 3. Logical Operators
Used to combine or invert conditions.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `&&`     | Logical AND      | `(a > 5) && (b < 5)`       |
| `||`     | Logical OR       | `(a > 5) || (b < 5)`       |
| `!`      | Logical NOT      | `!a`           |

### 4. Assignment Operators
Used to assign values to variables.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `=`      | Assignment       | `a = b`        |
| `+=`     | Add and assign   | `a += b`       |
| `-=`     | Subtract and assign | `a -= b`    |
| `*=`     | Multiply and assign | `a *= b`    |
| `/=`     | Divide and assign   | `a /= b`    |
| `%=`     | Modulus and assign  | `a %= b`    |

### 5. Increment and Decrement Operators
Used to increase or decrease value by one.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `++`     | Increment        | `a++` or `++a` |
| `--`     | Decrement        | `a--` or `--a` |

### 6. Bitwise Operators
Operate on bits of integer data.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `&`      | Bitwise AND      | `a & b`        |
| `&#124;` | Bitwise OR       | `a &#124; b`   |
| `^`      | Bitwise XOR      | `a ^ b`        |
| `~`      | Bitwise NOT      | `~a`           |
| `<<`     | Left shift       | `a << 2`       |
| `>>`     | Right shift      | `a >> 2`       |

### 7. Conditional (Ternary) Operator
Short form for if-else.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `?:`     | Ternary          | `a ? b : c`    |

### 8. Miscellaneous Operators
Other useful operators.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `sizeof` | Size of data type| `sizeof(int)`  |
| `&`      | Address of       | `&a`           |
| `*`      | Pointer to       | `*ptr`         |

---

## Unary and Binary Operators

- **Unary operators** operate on a single operand.
  - Examples: `++a`, `--b`, `!flag`, `~x`, `sizeof(a)`, `&x`, `*ptr`
- **Binary operators** operate on two operands.
  - Examples: `a + b`, `x - y`, `a && b`, `a || b`, `a | b`, `a = b`

---

## How Operators Work

Operators take one (unary) or two (binary) operands and perform a specific operation.  
For example, `a + b` adds the values of `a` and `b`, while `!flag` inverts the boolean value of `flag`.

Operator precedence determines the order in which operations are performed.  
For example, in `a + b * c`, multiplication is performed before addition.

---

## Examples

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    printf("Addition: %d\n", a + b);         // Arithmetic (binary)
    printf("Negation: %d\n", -a);            // Arithmetic (unary)
    printf("Equal: %d\n", a == b);           // Relational
    printf("Logical AND: %d\n", (a > 5) && (b < 5)); // Logical
    printf("Logical OR: %d\n", (a > 5) || (b < 5));  // Logical OR
    a += 5;                                  // Assignment
    printf("Incremented a: %d\n", ++a);      // Increment (unary)
    printf("Bitwise AND: %d\n", a & b);      // Bitwise AND
    printf("Bitwise OR: %d\n", a | b);       // Bitwise OR
    int max = (a > b) ? a : b;               // Ternary
    printf("Max: %d\n", max);
    printf("Size of int: %lu\n", sizeof(int)); // Miscellaneous
    int *ptr = &a;
    printf("Pointer value: %d\n", *ptr);     // Pointer dereference (unary)
    return 0;
}
```

---

## Summary

- Operators are used for calculations, comparisons, assignments, and more.
- Unary operators work on one operand; binary operators work on two.
- Operator precedence affects how expressions are evaluated.
- Understanding operators is key to writing efficient and correct C programs.