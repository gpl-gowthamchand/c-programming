# Storage Classes in C Programming

Storage classes in C determine the scope, lifetime, and memory location of variables. They control how variables are stored in memory and how long they persist during program execution.

## Types of Storage Classes

### 1. **auto** Storage Class
- **Default storage class** for local variables
- Variables are stored in **stack memory**
- **Scope**: Local to the block/function where declared
- **Lifetime**: Exists only within the block/function
- **Initial value**: Garbage value (uninitialized)

```c
#include <stdio.h>

int main() {
    auto int x = 10;  // 'auto' is optional, same as: int x = 10;
    
    {
        auto int y = 20;  // Local to this block
        printf("y = %d\n", y);
    }
    // y is not accessible here
    
    printf("x = %d\n", x);
    return 0;
}
```

### 2. **register** Storage Class
- Suggests to compiler to store variable in **CPU registers** for faster access
- **Scope**: Local to the block/function where declared
- **Lifetime**: Exists only within the block/function
- **Initial value**: Garbage value
- **Note**: Compiler may ignore this suggestion

```c
#include <stdio.h>

int main() {
    register int counter;  // Suggests storing in CPU register
    
    for(counter = 0; counter < 1000; counter++) {
        // Fast access for loop counter
    }
    
    return 0;
}
```

### 3. **static** Storage Class
- Variables retain their value between function calls
- **Scope**: Local to the block/function where declared
- **Lifetime**: Entire program execution
- **Memory**: Data segment
- **Initial value**: Zero (0) by default

```c
#include <stdio.h>

void function() {
    static int count = 0;  // Retains value between calls
    count++;
    printf("Function called %d times\n", count);
}

int main() {
    function();  // Output: Function called 1 times
    function();  // Output: Function called 2 times
    function();  // Output: Function called 3 times
    return 0;
}
```

**Static Global Variables:**
```c
#include <stdio.h>

static int globalVar = 100;  // Only accessible within this file

void func() {
    printf("Global var: %d\n", globalVar);
}
```

### 4. **extern** Storage Class
- Used to declare variables that are defined elsewhere
- **Scope**: Global (entire program)
- **Lifetime**: Entire program execution
- **Memory**: Data segment
- **Purpose**: Link variables across multiple source files

**File 1 (main.c):**
```c
#include <stdio.h>

extern int globalVar;  // Declaration only

int main() {
    printf("Global var: %d\n", globalVar);
    return 0;
}
```

**File 2 (globals.c):**
```c
int globalVar = 50;  // Definition
```

### 5. **const** Storage Class
- Variables cannot be modified after initialization
- **Scope**: Depends on where declared
- **Lifetime**: Depends on storage class used
- **Memory**: Usually in data segment

```c
#include <stdio.h>

int main() {
    const int MAX_SIZE = 100;
    const float PI = 3.14159;
    
    // MAX_SIZE = 200;  // Error: cannot modify const variable
    
    printf("Max size: %d\n", MAX_SIZE);
    printf("PI: %f\n", PI);
    
    return 0;
}
```

## Memory Layout and Storage Classes

```
Memory Layout:
┌─────────────────┐
│   Stack         │ ← auto, register variables
│                 │
├─────────────────┤
│   Heap          │ ← dynamically allocated memory
│                 │
├─────────────────┤
│   Data Segment  │ ← static, extern, const variables
│   (Initialized) │
├─────────────────┤
│   BSS Segment   │ ← uninitialized static variables
│                 │
├─────────────────┤
│   Code Segment  │ ← program instructions
└─────────────────┘
```

## Summary Table

| Storage Class | Scope | Lifetime | Memory | Initial Value | Keyword |
|---------------|-------|----------|---------|---------------|---------|
| **auto** | Local | Block | Stack | Garbage | `auto` (optional) |
| **register** | Local | Block | CPU Register | Garbage | `register` |
| **static** | Local | Program | Data Segment | 0 | `static` |
| **extern** | Global | Program | Data Segment | 0 | `extern` |
| **const** | Depends | Depends | Data Segment | Must initialize | `const` |

## Best Practices

1. **Use `static`** for variables that need to persist between function calls
2. **Use `extern`** for sharing variables across multiple source files
3. **Use `const`** for values that should never change
4. **Avoid `register`** in modern C (compilers are smart enough)
5. **`auto`** is rarely explicitly used (it's the default)

## Common Use Cases

### Static Variables in Functions
```c
int getNextId() {
    static int id = 0;
    return ++id;
}
```

### Extern for Header Files
```c
// header.h
extern int sharedVariable;

// source.c
int sharedVariable = 42;
```

### Const for Configuration
```c
const int BUFFER_SIZE = 1024;
const char* CONFIG_FILE = "config.txt";
```

## Compiler Behavior

- Modern C compilers are smart about optimization
- `register` keyword is often ignored
- `static` variables are optimized for memory access
- `const` variables may be placed in read-only memory
- Storage class affects variable initialization and cleanup
