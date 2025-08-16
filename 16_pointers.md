# Pointers in C Programming

## 🧭 **Navigation**
| ⬅️ Previous | 🏠 Home | ➡️ Next |
|:------------|:--------|:--------|
| [15 Enums](15_enums.md) | [README](README.md) | [17 Dynamic Memory Allocation](17_dynamic_memory_allocation.md) |

---

## Introduction
Pointers are one of the most powerful and fundamental concepts in C programming. They allow you to directly manipulate memory addresses and create efficient, flexible programs.

## What are Pointers?
A pointer is a variable that stores the memory address of another variable. Instead of storing a value directly, a pointer stores the location where a value is stored in memory.

## Basic Syntax

### Declaring Pointers
```c
int *ptr;        // Pointer to an integer
char *cptr;      // Pointer to a character
float *fptr;     // Pointer to a float
double *dptr;    // Pointer to a double
```

### Address Operator (&)
The `&` operator returns the memory address of a variable:
```c
int number = 42;
int *ptr = &number;  // ptr now contains the address of number
```

### Dereference Operator (*)
The `*` operator is used to access the value stored at the address pointed to by a pointer:
```c
int number = 42;
int *ptr = &number;
printf("Value: %d\n", *ptr);  // Prints: Value: 42
```

## Basic Pointer Operations

### Example 1: Basic Pointer Usage
```c
#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;
    
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    
    return 0;
}
```

### Example 2: Modifying Values Through Pointers
```c
#include <stdio.h>

int main() {
    int number = 100;
    int *ptr = &number;
    
    printf("Before: number = %d\n", number);
    
    *ptr = 200;  // Modify the value through the pointer
    
    printf("After: number = %d\n", number);
    
    return 0;
}
```

## Null Pointers
A null pointer is a pointer that doesn't point to any valid memory location. It's represented by `NULL`:

```c
int *ptr = NULL;  // Initialize pointer to NULL

if (ptr == NULL) {
    printf("Pointer is NULL\n");
}
```

## Pointer Arithmetic
Pointers support arithmetic operations:

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // Points to first element
    
    printf("First element: %d\n", *ptr);
    printf("Second element: %d\n", *(ptr + 1));
    printf("Third element: %d\n", *(ptr + 2));
    
    return 0;
}
```

## Pointers and Arrays
Arrays and pointers are closely related in C. In fact, an array name is essentially a pointer to the first element of the array.

### Array Name as a Pointer
```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    // arr is equivalent to &arr[0]
    printf("arr: %p\n", (void*)arr);
    printf("&arr[0]: %p\n", (void*)&arr[0]);
    
    // Both are the same
    if (arr == &arr[0]) {
        printf("arr and &arr[0] are equal!\n");
    }
    
    return 0;
}
```

### Different Ways to Access Array Elements
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    
    printf("=== Array Notation ===\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\n=== Pointer Notation ===\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }
    
    printf("\n=== Alternative Pointer Notation ===\n");
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    return 0;
}
```

### Pointer Arithmetic with Arrays
```c
#include <stdio.h>

int main() {
    int arr[] = {100, 200, 300, 400, 500};
    int *ptr = arr;
    
    printf("Initial ptr points to: %d\n", *ptr);
    
    ptr++;  // Move to next element
    printf("After ptr++: %d\n", *ptr);
    
    ptr += 2;  // Move 2 elements forward
    printf("After ptr += 2: %d\n", *ptr);
    
    ptr--;  // Move back 1 element
    printf("After ptr--: %d\n", *ptr);
    
    ptr -= 2;  // Move back 2 elements
    printf("After ptr -= 2: %d\n", *ptr);
    
    return 0;
}
```

### Multi-dimensional Arrays and Pointers
```c
#include <stdio.h>

int main() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Pointer to first element
    int *ptr = &matrix[0][0];
    
    printf("=== Using Single Pointer ===\n");
    for (int i = 0; i < 12; i++) {
        printf("%2d ", *(ptr + i));
        if ((i + 1) % 4 == 0) printf("\n");
    }
    
    // Pointer to first row
    int (*row_ptr)[4] = matrix;
    
    printf("\n=== Using Row Pointer ===\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", row_ptr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

### Memory Layout of 2D Arrays
Let's say we have:
```c
int arr[3][4];
```

This means 3 rows and 4 columns.

**Memory is contiguous** — all elements are stored one after another in **row-major order**:
```
arr[0][0], arr[0][1], arr[0][2], arr[0][3],
arr[1][0], arr[1][1], arr[1][2], arr[1][3],
arr[2][0], arr[2][1], arr[2][2], arr[2][3]
```

#### 2️⃣ Accessing Elements
You normally use:
```c
arr[row][col]
```

But pointers can also be used.

- **`arr`** → points to the first row (type: `int (*)[4]` — pointer to an array of 4 ints)
- **`arr + i`** → points to the i-th row
- **`*(arr + i)`** → gives the base address of the i-th row (type: `int*`)
- **`*(*(arr + i) + j)`** → gives `arr[i][j]`

**Example:**
```c
printf("%d", *(*(arr + 1) + 2)); // Same as arr[1][2]
```

#### 3️⃣ Example Code
```c
#include <stdio.h>

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Using normal indexing
    printf("arr[1][2] = %d\n", arr[1][2]);

    // Using pointer arithmetic
    printf("*( *(arr + 1) + 2 ) = %d\n", *(*(arr + 1) + 2));

    // Printing addresses
    printf("arr = %p\n", (void*)arr);
    printf("arr + 1 (next row) = %p\n", (void*)(arr + 1));
    printf("*(arr + 1) (start of row 1) = %p\n", (void*)*(arr + 1));
    printf("*(arr + 1) + 2 (3rd element in row 1) = %p\n", (void*)(*(arr + 1) + 2));

    return 0;
}
```

### Advanced 2D Arrays and Pointers

#### 1. Memory Layout of 2D Arrays

A 2D array in C is stored row-wise in contiguous memory.

**Example:**
```c
int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
```

**Memory layout:**
```
Address	Value
1000	1
1004	2
1008	3
1012	4
1016	5
1020	6
```

#### 2. Pointer to 2D Array vs. Pointer to Pointer

**Pointer to Array**
```c
int (*p)[3] = arr;
```

`p` is a pointer to an array of 3 integers.

`p + 1` → jumps 3 integers ahead.

**Pointer to Pointer**
```c
int *q[2];  // Array of int pointers
q[0] = arr[0];
q[1] = arr[1];
```

This is not the same as a 2D array in memory.

Each row can be at different memory locations (useful for dynamic allocation).

#### 3. Accessing Elements

If:
```c
int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
```

| Access Method | Meaning |
|---------------|---------|
| `arr[i][j]` | Direct indexing |
| `*(*(arr + i) + j)` | Pointer arithmetic |
| `(*(arr + i))[j]` | Array pointer dereference |
| `*(&arr[0][0] + i * 3 + j)` | Linear memory access |

#### 4. Passing 2D Arrays to Functions

When passing to a function, you must specify the column size:

```c
void printArray(int arr[][3], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
```

**or:**

```c
void printArray(int (*arr)[3], int rows);
```

#### 5. Dynamic 2D Arrays Using Pointers
```c
int **matrix = malloc(rows * sizeof(int*));
for(int i = 0; i < rows; i++)
    matrix[i] = malloc(cols * sizeof(int));
```

Each `matrix[i]` is separately allocated.

#### 6. Key Differences

| Static 2D Array | Pointer to Pointer |
|------------------|-------------------|
| Contiguous memory | Can be scattered in memory |
| Faster access | Slightly slower (extra indirection) |
| Requires known column size | Flexible sizes |

### Practical Examples: Different 2D Array Approaches

#### 1. Fixed 2D Array (contiguous memory)
```c
#include <stdio.h>

int main() {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int *p = &arr[0][0];  // pointer to first element

    printf("arr[0][0] = %d\n", *p);         // 1
    printf("arr[0][1] = %d\n", *(p + 1));   // 2
    printf("arr[1][0] = %d\n", *(p + 3));   // 4

    return 0;
}
```

👉 Here memory is continuous, so pointer arithmetic works like a 1D flattened array.

#### 2. Array of Pointers (jagged array style)
```c
#include <stdio.h>

int main() {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int *arr[2];   // array of int pointers

    arr[0] = row1;
    arr[1] = row2;

    printf("arr[0][0] = %d\n", arr[0][0]);  // 1
    printf("arr[0][1] = %d\n", arr[0][1]);  // 2
    printf("arr[1][0] = %d\n", arr[1][0]);  // 4
    printf("arr[1][2] = %d\n", arr[1][2]);  // 6

    return 0;
}
```

👉 Here memory is not necessarily continuous. Each row can be separate, because we store row pointers.

#### 3. Pointer to Pointer (int ** )
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 2, cols = 3;
    int **arr;

    // allocate row pointers
    arr = (int **)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    // assign values
    int count = 1;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            arr[i][j] = count++;
        }
    }

    // print
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

👉 This is dynamic 2D array allocation using pointer to pointer.

### Double Pointers (Pointers to Pointers)

#### What is a Double Pointer?

A pointer stores the address of a variable.

A double pointer stores the address of another pointer.

👉 **Example:**
```c
#include <stdio.h>

int main() {
    int a = 10;

    int *p = &a;    // p stores the address of a
    int **q = &p;   // q stores the address of p

    printf("a  = %d\n", a);
    printf("*p = %d\n", *p);
    printf("**q = %d\n", **q);

    return 0;
}
```

✅ **Output:**
```
a  = 10
*p = 10
**q = 10
```

#### 2. Understanding with Memory

- **a** → value 10 stored.
- **p** → stores address of a.
- **q** → stores address of p.

**So:**
- **`*p`** → value at address stored in p → a.
- **`**q`** → value at address stored in *q → a.

#### 🔹 Double Pointers with Arrays

##### 1. Array + Pointer Recap
```c
int arr[3] = {10, 20, 30};
int *p = arr;   // points to arr[0]
```

`p` is a pointer to the first element.

`p + 1` → points to `arr[1]`.

##### 2. Double Pointer with Array of Pointers

You can store multiple array addresses inside a pointer-to-pointer.

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;

    int *arr[3] = {&a, &b, &c};  // array of pointers
    int **pp = arr;              // double pointer points to arr[0]

    printf("%d\n", **pp);        // prints 10
    printf("%d\n", **(pp + 1));  // prints 20
    printf("%d\n", **(pp + 2));  // prints 30

    return 0;
}
```

✅ **Output:**
```
10
20
30
```

##### 3. Double Pointer with 2D Array
```c
#include <stdio.h>

int main() {
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int *p[2];    // array of pointers
    p[0] = arr[0]; // points to row 0
    p[1] = arr[1]; // points to row 1

    int **pp = p; // double pointer to array of pointers

    printf("%d\n", pp[0][1]); // 2
    printf("%d\n", pp[1][2]); // 6

    return 0;
}
```

✅ **Output:**
```
2
6
```

### Passing 2D Arrays to Functions

A 2D array is actually stored in contiguous memory row by row.
When you pass it to a function, it decays into a pointer to its first row.

#### ✅ Example: Passing 2D Array to Function
```c
#include <stdio.h>

// Function to print a 2D array
void printArray(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Passing 2D array to function
    printArray(arr, 2);

    return 0;
}
```

#### 🔎 Key Points

In function declaration, you must specify the number of columns (`[3]` here).

✅ `void func(int arr[][3], int rows)` → Works

❌ `void func(int arr[][], int rows)` → Doesn't work

Inside the function, `arr` is treated as a pointer to 1D arrays (rows).
So:

- **`arr`** → points to row 0 (`arr[0]`)
- **`*(arr+i)`** → points to row i
- **`*(*(arr+i) + j)`** → element at row i, column j

### Array of Pointers
```c
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30, d = 40;
    
    // Array of pointers to integers
    int *ptr_array[] = {&a, &b, &c, &d};
    
    printf("=== Array of Pointers ===\n");
    for (int i = 0; i < 4; i++) {
        printf("ptr_array[%d] points to: %d\n", i, *ptr_array[i]);
    }
    
    // Modifying values through array of pointers
    *ptr_array[0] = 100;
    *ptr_array[1] = 200;
    
    printf("\nAfter modification:\n");
    printf("a = %d, b = %d\n", a, b);
    
    return 0;
}
```

### Pointer to Array
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Pointer to an array of 5 integers
    int (*array_ptr)[5] = &arr;
    
    printf("=== Pointer to Array ===\n");
    printf("Size of array_ptr: %zu bytes\n", sizeof(*array_ptr));
    printf("Size of arr: %zu bytes\n", sizeof(arr));
    
    // Accessing elements
    for (int i = 0; i < 5; i++) {
        printf("(*array_ptr)[%d] = %d\n", i, (*array_ptr)[i]);
    }
    
    return 0;
}
```

### Dynamic Arrays with Pointers
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    
    // Dynamically allocate array
    int *dynamic_arr = (int*)malloc(size * sizeof(int));
    
    if (dynamic_arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        dynamic_arr[i] = (i + 1) * 10;
    }
    
    // Display array
    printf("Dynamic array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamic_arr[i]);
    }
    printf("\n");
    
    // Free allocated memory
    free(dynamic_arr);
    dynamic_arr = NULL;
    
    return 0;
}
```

### Common Array-Pointer Operations
```c
#include <stdio.h>

int main() {
    int arr[] = {5, 15, 25, 35, 45};
    int *ptr = arr;
    
    printf("=== Common Operations ===\n");
    
    // Get array length (only works for arrays, not pointers)
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    printf("Array length: %d\n", arr_length);
    
    // Pointer arithmetic
    printf("First element: %d\n", *ptr);
    printf("Last element: %d\n", *(ptr + arr_length - 1));
    printf("Middle element: %d\n", *(ptr + arr_length / 2));
    
    // Compare pointers
    int *end_ptr = ptr + arr_length;
    printf("Elements between ptr and end_ptr:\n");
    while (ptr < end_ptr) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
    
    return 0;
}
```

## Pointers to Functions
Pointers can also point to functions:

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int (*operation)(int, int);  // Function pointer
    
    operation = add;
    printf("Addition: %d\n", operation(5, 3));
    
    operation = multiply;
    printf("Multiplication: %d\n", operation(5, 3));
    
    return 0;
}
```

## Common Pitfalls and Best Practices

### 1. Always Initialize Pointers
```c
int *ptr;        // Bad - uninitialized pointer
int *ptr = NULL; // Good - initialized to NULL
```

### 2. Check for NULL Before Dereferencing
```c
if (ptr != NULL) {
    printf("Value: %d\n", *ptr);
}
```

### 3. Be Careful with Pointer Arithmetic
```c
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
// Don't go beyond array bounds
// *(ptr + 10) would be dangerous!
```

## Memory Management
When working with pointers, be mindful of memory:

```c
#include <stdlib.h>

int main() {
    // Dynamic memory allocation
    int *ptr = (int*)malloc(sizeof(int));
    
    if (ptr != NULL) {
        *ptr = 42;
        printf("Value: %d\n", *ptr);
        
        // Always free allocated memory
        free(ptr);
        ptr = NULL;  // Good practice after freeing
    }
    
    return 0;
}
```

## Summary
Pointers are essential in C programming for:
- Efficient memory management
- Dynamic data structures
- Function pointers
- Array manipulation
- Passing parameters by reference

Understanding pointers is crucial for becoming proficient in C programming and understanding how memory works at a low level.

