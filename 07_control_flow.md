# Control Flow Statements in C Programming

Control flow statements determine the order in which instructions are executed in a C program.  
They allow you to make decisions, repeat actions, and jump to different parts of your code, making your programs flexible and logical.

## Types of Control Flow Statements

### 1. Conditional Statements

Conditional statements let you choose which code to execute based on certain conditions.

- **if**  
  Use when you want to execute code only if a condition is true.
  ```c
  if (score >= 50) {
      printf("You passed!\n");
  }
  ```
  *Use case:* Checking if a user input meets a requirement.

- **if-else**  
  Use when you want to execute one block if the condition is true, and another if it is false.
  ```c
  if (num % 2 == 0) {
      printf("Even\n");
  } else {
      printf("Odd\n");
  }
  ```
  *Use case:* Handling two possible outcomes.

- **if-else if-else**  
  Use when you have multiple conditions to check in sequence.
  ```c
  if (marks >= 90) {
      printf("Grade A\n");
  } else if (marks >= 75) {
      printf("Grade B\n");
  } else {
      printf("Grade C\n");
  }
  ```
  *Use case:* Assigning grades based on score ranges.

- **switch**  
  Use when you need to select one of many code blocks based on the value of a variable (usually integer or char).
  ```c
  switch (day) {
      case 1: printf("Monday\n"); break;
      case 2: printf("Tuesday\n"); break;
      default: printf("Other day\n");
  }
  ```
  *Use case:* Menu selection, handling multiple discrete options.

- **Ternary Operator**  
  Use for simple conditional assignments in a single line.
  ```c
  int max = (a > b) ? a : b;
  ```
  *Use case:* Assigning a value based on a condition concisely.

---

### 2. Looping Statements

Looping statements let you repeat a block of code multiple times.

- **for loop**  
  Use when you know in advance how many times you want to repeat an action.
  ```c
  for (int i = 0; i < 5; i++) {
      printf("%d\n", i);
  }
  ```
  *Use case:* Iterating over arrays, counting, fixed repetitions.

- **while loop**  
  Use when you want to repeat an action as long as a condition remains true.
  ```c
  int i = 0;
  while (i < 5) {
      printf("%d\n", i);
      i++;
  }
  ```
  *Use case:* Waiting for user input, reading data until a condition is met.

- **do-while loop**  
  Use when you want to execute the loop body at least once, regardless of the condition.
  ```c
  int i = 0;
  do {
      printf("%d\n", i);
      i++;
  } while (i < 5);
  ```
  *Use case:* Menu-driven programs, input validation.

- **Infinite Loops**  
  Use when you want a loop to run forever until manually stopped (with `break` or exit key).
  ```c
  while (1) {
      // runs forever
  }
  ```
  Or:
  ```c
  for (;;) {
      // also infinite
  }
  ```
  *Use case:* Servers, embedded systems, waiting for events.

---

### 3. Jump Statements

Jump statements alter the normal flow of execution.

- **break**  
  Use to exit from loops or switch statements immediately.
  ```c
  for (int i = 0; i < 10; i++) {
      if (i == 5) break;
      printf("%d\n", i);
  }
  ```
  *Use case:* Stopping a loop when a condition is met.

- **continue**  
  Use to skip the current iteration and continue with the next one.
  ```c
  for (int i = 0; i < 5; i++) {
      if (i == 2) continue;
      printf("%d\n", i);
  }
  ```
  *Use case:* Skipping unwanted values in a loop.

- **return**  
  Use to exit from a function and optionally return a value.
  ```c
  int add(int a, int b) {
      return a + b;
  }
  ```
  *Use case:* Ending a function early, returning results.

- **goto** (rarely used, not recommended)  
  Use to jump to a labeled statement in the code.
  ```c
  int i = 0;
  start:
      printf("%d\n", i);
      i++;
      if (i < 3) goto start;
  ```
  *Use case:* Very rare; usually better alternatives exist.

---

## Summary

- Use **conditional statements** to make decisions (`if`, `switch`, ternary).
- Use **looping statements** to repeat actions (`for`, `while`, `do-while`, infinite loops).
- Use **jump statements** to change flow (`break`, `continue`, `return`, `goto`).

Choose the right control flow statement based on your program's logic and requirements.