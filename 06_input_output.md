# Input and Output in C Programming

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](05_operators.md) | [🏠 Home](README.md) | [➡️ Next](07_control_flow.md)

</div>

---


Input and output (I/O) operations allow a C program to interact with the user or other systems.  
The standard library provides functions for reading input and displaying output.

## Output Functions

### `printf()`
- Used to display text and variable values on the screen.
- Supports format specifiers for different data types.

**Example:**
```c
#include <stdio.h>

int main() {
    int age = 20;
    float height = 5.9;
    printf("Age: %d\n", age);         // %d for int
    printf("Height: %.1f\n", height); // %f for float
    printf("Hello, World!\n");        // prints a string
    return 0;
}
```

### Format Specifiers
- `%d` : integer
- `%f` : float/double (in printf)
- `%c` : character
- `%s` : string
- `%lf` : double (in scanf)

---

## Input Functions

### `scanf()`
- Used to read input from the user.
- Requires the address of the variable (except for strings).

**Example:**
```c
#include <stdio.h>

int main() {
    int num;
    float fnum;
    char ch;
    char str[20];

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter a float: ");
    scanf("%f", &fnum);

    printf("Enter a character: ");
    scanf(" %c", &ch); // space before %c to consume newline

    printf("Enter a string: ");
    scanf("%s", str); // no & needed for arrays (strings)

    printf("\nYou entered: %d, %.2f, %c, %s\n", num, fnum, ch, str);
    return 0;
}
```

### Notes on `scanf()`
- For strings, do **not** use `&` before the variable name.
- For characters, use `" %c"` to avoid reading leftover newline characters.
- For double, use `%lf` in `scanf()` and `%f` in `printf()`.

---

## Other I/O Functions

- `getchar()` : Reads a single character from input.
- `putchar()` : Writes a single character to output.
- `gets()` and `puts()` : Used for string input/output (not recommended, use `fgets()` instead for safety).

**Example:**
```c
char c = getchar();   // reads a character
putchar(c);           // prints a character

char line[50];
fgets(line, sizeof(line), stdin); // safe way to read a string
puts(line);                      // prints the string
```

---

## Summary

- Use `printf()` for output and `scanf()` for input.
- Always match format specifiers with variable types.
- For string input, use arrays and avoid using `&` in `scanf`.
- For safe string input, prefer `fgets()` over `gets()`.

Input and output are essential for interactive C programs and for communicating with users.

---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](05_operators.md) | [🏠 Home](README.md) | [➡️ Next](07_control_flow.md)

</div>