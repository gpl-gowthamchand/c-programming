# Control Flow Statements in C Programming

Control flow statements determine the order in which instructions are executed in a C program.  
They allow for decision making, looping, and jumping to different parts of code.

## Types of Control Flow Statements

### 1. Conditional Statements

Used to make decisions based on conditions.

- **if**
  ```c
  if (condition) {
      // code if condition is true
  }
  ```
- **if-else**
  ```c
  if (condition) {
      // code if true
  } else {
      // code if false
  }
  ```
- **if-else if-else**
  ```c
  if (cond1) { ... }
  else if (cond2) { ... }
  else { ... }
  ```
- **switch**
  ```c
  switch (expression) {
      case value1: ... break;
      case value2: ... break;
      default: ...;
  }
  ```
- **Ternary Operator**
  ```c
  int max = (a > b) ? a : b;
  ```

---

### 2. Looping Statements

Used to repeat a block of code multiple times.

- **for loop**
  ```c
  for (int i = 0; i < 5; i++) {
      printf("%d\n", i);
  }
  ```
- **while loop**
  ```c
  int i = 0;
  while (i < 5) {
      printf("%d\n", i);
      i++;
  }
  ```
- **do-while loop**
  ```c
  int i = 0;
  do {
      printf("%d\n", i);
      i++;
  } while (i < 5);
  ```

---

### 3. Jump Statements

Used to alter the normal flow of execution.

- **break**
  - Exits from loops or switch statements.
  ```c
  for (int i = 0; i < 10; i++) {
      if (i == 5) break;
      printf("%d\n", i);
  }
  ```
- **continue**
  - Skips the current iteration and continues with the next.
  ```c
  for (int i = 0; i < 5; i++) {
      if (i == 2) continue;
      printf("%d\n", i);
  }
  ```
- **return**
  - Exits from a function and optionally returns a value.
  ```c
  int add(int a, int b) {
      return a + b;
  }
  ```
- **goto** (rarely used, not recommended)
  - Jumps to a labeled statement.
  ```c
  int i = 0;
  start:
      printf("%d\n", i);
      i++;
      if (i < 3) goto start;
  ```

---

## Summary

- **Conditional statements**: Make decisions (`if`, `switch`, ternary).
- **Looping statements**: Repeat code (`for`, `while`, `do-while`).
- **Jump statements**: Change flow (`break`, `continue`, `return`, `goto`).

Control flow statements are essential for writing flexible and logical C programs.