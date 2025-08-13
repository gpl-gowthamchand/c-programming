# Tokens in C Programming

In C programming, **tokens** are the smallest units of a program that have meaning to the compiler.  
They are the building blocks for writing C programs.

## Types of Tokens

1. **Keywords**  
   Reserved words with special meaning.  
   *Example:* `int`, `return`, `if`, `while`

2. **Identifiers**  
   Names given to variables, functions, etc.  
   *Example:* `main`, `count`, `sum`

3. **Constants**  
   Fixed values that do not change during program execution.  
   *Example:* `10`, `3.14`, `'A'`

4. **String Literals**  
   Sequence of characters enclosed in double quotes.  
   *Example:* `"Hello, World!"`

5. **Operators**  
   Symbols that perform operations on variables and values.  
   *Example:* `+`, `-`, `*`, `/`, `=`

6. **Separators (Punctuators)**  
   Characters that separate tokens.  
   *Example:* `;`, `,`, `()`, `{}`

## Examples

```c
int sum = 10; // 'int' (keyword), 'sum' (identifier), '=' (operator), '10' (constant), ';' (separator)
printf("Hello, World!"); // 'printf' (identifier), '(' and ')' (separators), '"Hello, World!"' (string literal), ';' (separator)
```

---
Tokens are fundamental to understanding how C programs are structured and interpreted by the compiler.