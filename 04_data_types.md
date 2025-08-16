# Data Types in C Programming

Data types in C specify the type of data that a variable can hold.  
They help the compiler allocate memory and interpret the data correctly.

## Basic Data Types

| Data Type      | Size (bytes) | Format Specifier         | Example Usage                |
|----------------|--------------|--------------------------|------------------------------|
| `int`          | 4            | `%d`                     | `int age = 25;`              |
| `float`        | 4            | `%f`                     | `float temp = 36.6;`         |
| `double`       | 8            | `%lf` (scanf), `%f` (printf) | `double pi = 3.14;`      |
| `char`         | 1            | `%c`                     | `char grade = 'A';`          |
| `char[]` (string) | varies    | `%s`                     | `char name[20] = "John";`    |
| `_Bool` / `bool` | 1          | `%d`                     | `_Bool flag = 1;`            |

> **Note:** Sizes may vary depending on system and compiler, but these are typical for most platforms.

## Usage

- **int**: Used for whole numbers (positive, negative, zero).
- **float**: Used for decimal numbers with single precision.
- **double**: Used for decimal numbers with double precision.
- **char**: Used for single characters.
- **char[] (string)**: Used for storing sequences of characters (strings).
- **_Bool / bool**: Used for boolean values (`0` for false, `1` for true).  
  To use `bool`, include `#include <stdbool.h>`.

## Format Specifiers

- `%d` for `int` and `bool`
- `%f` for `float` and for `double` in `printf`
- `%lf` for `double` in `scanf`
- `%c` for `char`
- `%s` for strings (`char[]`)

> **Important:**  
> For `double`, use `%f` in `printf` and `%lf` in `scanf`:
> - `printf("%f", myDouble);` // prints double value
> - `scanf("%lf", &myDouble);` // reads double value

## Taking Input for Different Data Types

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    int num;
    float fnum;
    double dnum;
    char ch;
    char inputStr[10];
    bool flag;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter a float: ");
    scanf("%f", &fnum);

    printf("Enter a double: ");
    scanf("%lf", &dnum);

    printf("Enter a character: ");
    scanf(" %c", &ch); // Note the space before %c to consume any leftover newline

    printf("Enter a string: ");
    scanf("%s", inputStr); // No & needed for arrays when passing to scanf for strings

    printf("Enter a boolean (0 or 1): ");
    scanf("%d", &flag);

    printf("\nYou entered:\n");
    printf("Integer: %d\n", num);
    printf("Float: %f\n", fnum);
    printf("Double: %f\n", dnum); // use %f for double in printf
    printf("Character: %c\n", ch);
    printf("String: %s\n", inputStr);
    printf("Boolean: %d\n", flag);

    return 0;
}
```

## Derived Data Types

- **Array**: Collection of elements of the same type.  
  *Example:* `int numbers[5];`
- **Pointer**: Stores the address of another variable.  
  *Example:* `int *ptr;`
- **Structure**: Group of variables of different types.  
  *Example:*  
  ```c
  struct Person {
      char name[50];
      int age;
  };
  ```
- **Union**: Stores different data types in the same memory location.  
  *Example:*  
  ```c
  union Data {
      int i;
      float f;
      char str[20];
  };
  ```

## Data Types and Memory Organization

- **Primitive data types** (`int`, `float`, etc.) are stored in memory as single blocks.
- **Arrays** are stored as contiguous blocks (like a queue, elements are accessed in order).
- **Structures** are stored as a collection of blocks, one for each member.
- **Unions** share the same memory location for all members.
- **Pointers** store the memory address of another variable.

> **Note:** Data types themselves do not behave like queues or stacks.  
> Queues and stacks are data structures that can be implemented using arrays, structures, or pointers.

---
Choosing the correct data type is important for efficient memory usage and program correctness.