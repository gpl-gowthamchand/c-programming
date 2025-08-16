# Identifiers and Variables in C Programming

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](02_tokens.md) | [🏠 Home](README.md) | [➡️ Next](04_data_types.md)

</div>

---


## Identifiers

**Identifiers** are names given to various program elements such as variables, functions, arrays, etc.  
They help uniquely identify these elements in your code.

### Rules for Identifiers
- Can contain letters (A-Z, a-z), digits (0-9), and underscores (_)
- Must begin with a letter or underscore
- Cannot be a reserved keyword (e.g., `int`, `return`)
- Case-sensitive (`Count` and `count` are different)

### Examples of Valid Identifiers
- `total`
- `_value`
- `sum1`
- `student_name`

### Examples of Invalid Identifiers
- `1value` (cannot start with a digit)
- `float` (reserved keyword)
- `my-value` (hyphen not allowed)

---

## Variables

**Variables** are named memory locations used to store data that can change during program execution.

### Types of Variables

1. **Local Variables**
   - Declared inside a function or block
   - Accessible only within that function/block
   - Example:
     ```c
     void func() {
         int x = 10; // local variable
     }
     ```

2. **Global Variables**
   - Declared outside all functions
   - Accessible from any function in the file
   - Example:
     ```c
     int count = 0; // global variable

     void func() {
         count++;
     }
     ```

3. **Static Variables**
   - Declared with `static` keyword
   - Retain their value between function calls
   - Example:
     ```c
     void func() {
         static int num = 0;
         num++;
         printf("%d", num);
     }
     ```

4. **Extern Variables**
   - Declared with `extern` keyword
   - Used to access variables defined in other files
   - Example:
     ```c
     extern int shared;
     ```

---

## Variables vs Constants

**Variables** can change their value during program execution, while **constants** have fixed values that do not change.

### Declaring Constants

- Use the `const` keyword or `#define` preprocessor directive.

#### Examples

```c
int age = 25;         // variable: value can change
age = 30;             // valid

const float PI = 3.14; // constant: value cannot change
// PI = 3.1415;        // invalid, will cause a compile error

#define MAX_SIZE 100   // constant using preprocessor
```

---

## Examples

```c
#include <stdio.h>

int globalVar = 100; // global variable

void demo() {
    int localVar = 10; // local variable
    static int staticVar = 0; // static variable
    staticVar++;
    printf("Local: %d, Static: %d, Global: %d\n", localVar, staticVar, globalVar);
}

int main() {
    demo();
    demo();

    const int daysInWeek = 7; // constant
    int x = 5;                // variable
    x = 10;                   // valid
    // daysInWeek = 8;        // invalid, will cause error

    printf("Days in a week: %d\n", daysInWeek);
    printf("x: %d\n", x);

    return 0;
}
```

---

## Use Cases

- Use **local variables** for temporary data within functions.
- Use **global variables** for data shared across multiple functions.
- Use **static variables** to preserve state between function calls.
- Use **extern variables** for sharing data between different source files.
- Use **constants** for values that should not change (like mathematical constants, array sizes).

---

Identifiers, variables, and constants are fundamental for organizing and managing data in your

---

## 🧭 **Navigation**
| ⬅️ Previous | 🏠 Home | ➡️ Next |
|:------------|:--------|:--------|
| [Tokens](02_tokens.md) | [README](README.md) | [Data Types](04_data_types.md) |

[⬆️ Back to Top](#identifiers-and-variables-in-c-programming)

---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](02_tokens.md) | [🏠 Home](README.md) | [➡️ Next](04_data_types.md)

</div>