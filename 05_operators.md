# Operators in C Programming

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](04_data_types.md) | [🏠 Home](README.md) | [➡️ Next](06_input_output.md)

</div>

---


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

**Example:**
```c
int a = 10, b = 3;
printf("Addition: %d\n", a + b);        // 13
printf("Subtraction: %d\n", a - b);    // 7
printf("Multiplication: %d\n", a * b); // 30
printf("Division: %d\n", a / b);       // 3
printf("Modulus: %d\n", a % b);        // 1
```

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

**Example:**
```c
printf("Equal: %d\n", a == b);         // 0 (false)
printf("Not Equal: %d\n", a != b);    // 1 (true)
printf("Greater: %d\n", a > b);       // 1 (true)
printf("Less: %d\n", a < b);          // 0 (false)
printf("Greater or Equal: %d\n", a >= b); // 1 (true)
printf("Less or Equal: %d\n", a <= b);    // 0 (false)
```

### 3. Logical Operators
Used to combine or invert conditions.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `&&`     | Logical AND      | `(a > 5) && (b < 5)`       |
| `||`     | Logical OR       | `(a > 5) || (b < 5)`       |
| `!`      | Logical NOT      | `!a`           |

**Example:**
```c
printf("Logical AND: %d\n", (a > 5) && (b < 5)); // 1 (true)
printf("Logical OR: %d\n", (a > 5) || (b > 5));  // 1 (true)
printf("Logical NOT: %d\n", !(a > 5));           // 0 (false)
```

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

**Example:**
```c
int x = 5;
x += 3; // x = x + 3; x becomes 8
x -= 2; // x = x - 2; x becomes 6
x *= 4; // x = x * 4; x becomes 24
x /= 6; // x = x / 6; x becomes 4
x %= 3; // x = x % 3; x becomes 1
```

### 5. Increment and Decrement Operators
Used to increase or decrease value by one.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `++`     | Increment        | `a++` or `++a` |
| `--`     | Decrement        | `a--` or `--a` |

**Example:**
```c
int y = 10;
y++; // y becomes 11
++y; // y becomes 12
y--; // y becomes 11
--y; // y becomes 10
```

### 6. Bitwise Operators
Operate on bits of integer data.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `&`      | Bitwise AND      | `a & b`        |
| `|`      | Bitwise OR       | `a | b`        |
| `^`      | Bitwise XOR      | `a ^ b`        |
| `~`      | Bitwise NOT      | `~a`           |
| `<<`     | Left shift       | `a << 2`       |
| `>>`     | Right shift      | `a >> 2`       |

**Example:**
```c
int a = 10, b = 3;
printf("Bitwise AND: %d\n", a & b);   // 2
printf("Bitwise OR: %d\n", a | b);    // 11
printf("Bitwise XOR: %d\n", a ^ b);   // 9
printf("Bitwise NOT: %d\n", ~a);      // -11
printf("Left Shift: %d\n", a << 1);   // 20
printf("Right Shift: %d\n", a >> 1);  // 5
```

### 7. Conditional (Ternary) Operator
Short form for if-else.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `?:`     | Ternary          | `condition ? value_if_true : value_if_false`    |

**Example:**
```c
int a = 10, b = 3;
int max = (a > b) ? a : b; // If a > b, max = a; else max = b
printf("Max value: %d\n", max);

int isEven = (a % 2 == 0) ? 1 : 0; // If a is even, isEven = 1; else isEven = 0
printf("Is a even? %d\n", isEven);
```

### 8. Miscellaneous Operators
Other useful operators.

| Operator | Description      | Example         |
|----------|------------------|----------------|
| `sizeof` | Size of data type| `sizeof(int)`  |
| `&`      | Address of       | `&a`           |
| `*`      | Pointer to       | `*ptr`         |

**Example:**
```c
int a = 10;
printf("Size of int: %lu\n", sizeof(int)); // 4 (on most systems)
printf("Address of a: %p\n", (void*)&a);   // prints address of a

int *ptr = &a;
printf("Pointer value: %d\n", *ptr);       // prints value at address
```

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

## Summary

- Operators are used for calculations, comparisons, assignments, and more.
- Unary operators work on one operand; binary operators work on two.
- Operator precedence affects how expressions are evaluated.
- Understanding operators is key to writing efficient and correct C programs.

---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](04_data_types.md) | [🏠 Home](README.md) | [➡️ Next](06_input_output.md)

</div>