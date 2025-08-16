# Types of Arrays in C Programming

## 🧭 **Navigation**
| ⬅️ Previous | 🏠 Home | ➡️ Next |
|:------------|:--------|:--------|
| [09 Intro To Arrays](09_intro_to_arrays.md) | [README](README.md) | [11 Array Examples](11_array_examples.md) |

---

## Table of Contents
1. [Introduction](#introduction)
2. [One-Dimensional Arrays](#one-dimensional-arrays)
3. [Multi-Dimensional Arrays](#multi-dimensional-arrays)
4. [Character Arrays (Strings)](#character-arrays-strings)
5. [Dynamic Arrays](#dynamic-arrays)
6. [Array of Pointers](#array-of-pointers)
7. [Array of Structures](#array-of-structures)
8. [Common Mistakes and Errors](#common-mistakes-and-errors)
9. [Best Practices](#best-practices)
10. [Performance Considerations](#performance-considerations)

## Introduction

Arrays are fundamental data structures in C that store multiple values of the same data type in contiguous memory locations. Understanding different types of arrays is crucial for efficient programming and memory management.

## One-Dimensional Arrays

### What They Are
One-dimensional arrays are the simplest form of arrays that store elements in a single row or column.

### How They Work
- Elements are stored in contiguous memory locations
- Each element can be accessed using an index (0-based indexing)
- Memory is allocated at compile time (for static arrays)

### Declaration and Initialization
```c
// Declaration
int numbers[5];           // Declares array of 5 integers
float prices[10];         // Declares array of 10 floats

// Initialization
int scores[5] = {85, 92, 78, 96, 88};  // Initialize with values
int ages[] = {25, 30, 35, 40};          // Size determined by initializer
int zeros[5] = {0};                     // Initialize all elements to 0
```

### Accessing Elements
```c
int numbers[5] = {10, 20, 30, 40, 50};

// Accessing elements
int first = numbers[0];    // 10
int third = numbers[2];    // 30
int last = numbers[4];     // 50

// Modifying elements
numbers[1] = 25;          // Changes second element to 25
```

### Use Cases
- Storing lists of data (grades, temperatures, etc.)
- Implementing simple data structures
- Buffer management
- Lookup tables

### Example: Grade Calculator
```c
#include <stdio.h>

int main() {
    int grades[5];
    int sum = 0;
    float average;
    
    // Input grades
    printf("Enter 5 grades:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &grades[i]);
        sum += grades[i];
    }
    
    // Calculate average
    average = (float)sum / 5;
    
    printf("Grades: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", grades[i]);
    }
    printf("\nAverage: %.2f\n", average);
    
    return 0;
}
```

## Multi-Dimensional Arrays

### What They Are
Multi-dimensional arrays store data in multiple dimensions (2D, 3D, etc.), useful for representing tables, matrices, and spatial data.

### How They Work
- Elements are stored in row-major order (C standard)
- Memory is still contiguous but organized in multiple dimensions
- Each dimension has its own index

### Two-Dimensional Arrays

#### Declaration and Initialization
```c
// Declaration
int matrix[3][4];                    // 3 rows, 4 columns
char grid[5][5];                     // 5x5 character grid

// Initialization
int table[2][3] = {
    {1, 2, 3},    // First row
    {4, 5, 6}     // Second row
};

// Partial initialization
int array[3][3] = {
    {1, 2},       // First row: 1, 2, 0
    {3, 4, 5},    // Second row: 3, 4, 5
    {6}           // Third row: 6, 0, 0
};
```

#### Accessing Elements
```c
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

// Accessing elements
int element = matrix[1][2];  // Row 1, Column 2 = 6

// Modifying elements
matrix[0][1] = 10;          // Changes element at row 0, column 1
```

#### Use Cases
- Matrix operations
- Game boards (chess, tic-tac-toe)
- Image processing
- Spreadsheet-like data

#### Example: Matrix Addition
```c
#include <stdio.h>

int main() {
    int matrix1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrix2[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int result[2][3];
    
    // Add matrices
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Display result
    printf("Result Matrix:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

### Three-Dimensional Arrays
```c
// Declaration
int cube[3][3][3];  // 3x3x3 cube

// Initialization
int array[2][2][2] = {
    {{1, 2}, {3, 4}},      // First 2D slice
    {{5, 6}, {7, 8}}       // Second 2D slice
};

// Accessing
int value = cube[1][2][0];  // Layer 1, Row 2, Column 0
```

## Character Arrays (Strings)

### What They Are
Character arrays are used to store strings in C. They are essentially one-dimensional arrays of characters with a null terminator ('\0') at the end.

### How They Work
- Each character occupies 1 byte
- String ends with null terminator '\0'
- String length is the number of characters before '\0'

### Declaration and Initialization
```c
// Declaration
char name[20];                    // Can store up to 19 characters + '\0'
char message[100];                // Can store up to 99 characters + '\0'

// Initialization
char greeting[] = "Hello";        // Automatically adds '\0'
char word[10] = "World";          // Explicit size
char empty[5] = "";               // Empty string with '\0' at index 0

// Character by character
char letters[4] = {'A', 'B', 'C', '\0'};
```

### String Operations
```c
#include <string.h>

char str1[20] = "Hello";
char str2[20] = "World";

// String length
int len = strlen(str1);           // 5

// String copy
strcpy(str1, "Hi");               // str1 becomes "Hi"

// String concatenation
strcat(str1, " there");           // str1 becomes "Hi there"

// String comparison
if(strcmp(str1, str2) == 0) {
    printf("Strings are equal\n");
}
```

### Use Cases
- Text processing
- User input handling
- File operations
- Data parsing

### Example: String Reversal
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    int len = strlen(str);
    
    printf("Original: %s\n", str);
    printf("Reversed: ");
    
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Dynamic Arrays

### What They Are
Dynamic arrays are arrays whose size is determined at runtime using dynamic memory allocation functions.

### How They Work
- Memory is allocated from the heap using `malloc()`, `calloc()`, or `realloc()`
- Size can be changed during program execution
- Must be manually freed using `free()`

### Memory Allocation Functions
```c
#include <stdlib.h>

// malloc - allocates memory without initialization
int *numbers = (int *)malloc(5 * sizeof(int));

// calloc - allocates memory and initializes to 0
int *zeros = (int *)calloc(5, sizeof(int));

// realloc - changes size of existing allocation
numbers = (int *)realloc(numbers, 10 * sizeof(int));

// free - deallocates memory
free(numbers);
```

### Example: Dynamic Array Implementation
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    
    // Allocate memory
    int *array = (int *)malloc(size * sizeof(int));
    
    if(array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input elements
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    // Display elements
    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Free memory
    free(array);
    
    return 0;
}
```

### Use Cases
- Programs with unknown data size requirements
- Data structures that grow/shrink
- Efficient memory usage
- Large datasets

## Array of Pointers

### What They Are
An array where each element is a pointer to another data type.

### How They Work
- Each array element stores a memory address
- Useful for managing multiple data structures
- Can point to different types of data

### Declaration and Usage
```c
// Array of integer pointers
int *ptr_array[5];

// Array of character pointers (array of strings)
char *names[] = {"Alice", "Bob", "Charlie", "David"};

// Array of function pointers
int (*func_ptr[3])(int, int);
```

### Example: Array of String Pointers
```c
#include <stdio.h>

int main() {
    char *fruits[] = {"Apple", "Banana", "Orange", "Grape"};
    int count = 4;
    
    printf("Fruits:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, fruits[i]);
    }
    
    return 0;
}
```

### Use Cases
- Command-line arguments
- Menu systems
- Polymorphic behavior
- Function dispatch tables

## Array of Structures

### What They Are
Arrays where each element is a structure, useful for managing collections of related data.

### How They Work
- Each array element contains multiple fields
- Memory layout is contiguous for each structure
- Access fields using dot operator with array indexing

### Declaration and Usage
```c
// Define structure
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Array of structures
struct Student class[30];

// Initialize
struct Student students[] = {
    {"Alice", 20, 3.8},
    {"Bob", 19, 3.5},
    {"Charlie", 21, 3.9}
};
```

### Example: Student Management System
```c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student students[3];
    
    // Input student data
    for(int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }
    
    // Display student data
    printf("\nStudent List:\n");
    for(int i = 0; i < 3; i++) {
        printf("%s, Age: %d, GPA: %.2f\n", 
               students[i].name, students[i].age, students[i].gpa);
    }
    
    return 0;
}
```

### Use Cases
- Database records
- Game entities
- Configuration data
- Complex data management

## Common Mistakes and Errors

### 1. Array Bounds Violation
```c
int numbers[5] = {1, 2, 3, 4, 5};
int value = numbers[5];  // ERROR: Accessing index 5 (out of bounds)
numbers[5] = 10;         // ERROR: Writing to index 5 (out of bounds)
```

**What happens:** Undefined behavior, memory corruption, program crashes

**How to avoid:** Always check array bounds before access

### 2. Forgetting Null Terminator
```c
char str[5] = "Hello";  // ERROR: No space for '\0'
```

**What happens:** String functions may read beyond array bounds

**How to avoid:** Always allocate space for null terminator

### 3. Memory Leaks
```c
int *array = malloc(100 * sizeof(int));
// ... use array ...
// Missing: free(array);  // ERROR: Memory leak
```

**What happens:** Memory is never freed, causing memory leaks

**How to avoid:** Always free dynamically allocated memory

### 4. Incorrect Array Size Calculation
```c
int array[5];
int size = sizeof(array) / sizeof(array[0]);  // Correct
int wrong_size = sizeof(array) / sizeof(int); // Also correct
int bad_size = sizeof(array) / 4;            // ERROR: Assumes int is 4 bytes
```

**What happens:** Incorrect size calculation leads to logic errors

**How to avoid:** Use `sizeof(array) / sizeof(array[0])` for portability

### 5. String Buffer Overflow
```c
char buffer[10];
strcpy(buffer, "This string is too long");  // ERROR: Buffer overflow
```

**What happens:** Memory corruption, security vulnerabilities

**How to avoid:** Use `strncpy()` or check string length first

### 6. Array Decay to Pointer
```c
void printArray(int arr[]) {
    int size = sizeof(arr) / sizeof(arr[0]);  // ERROR: arr is a pointer
    // size will be incorrect
}
```

**What happens:** `sizeof(arr)` returns pointer size, not array size

**How to avoid:** Pass array size as separate parameter

## Best Practices

### 1. Always Initialize Arrays
```c
// Good
int numbers[5] = {0};  // Initialize all to 0
char buffer[100] = {0}; // Initialize all to '\0'

// Bad
int numbers[5];  // Contains garbage values
```

### 2. Use Constants for Array Sizes
```c
#define MAX_STUDENTS 100
#define BUFFER_SIZE 1024

int students[MAX_STUDENTS];
char buffer[BUFFER_SIZE];
```

### 3. Check Array Bounds
```c
int getElement(int arr[], int size, int index) {
    if(index >= 0 && index < size) {
        return arr[index];
    }
    return -1;  // Error indicator
}
```

### 4. Use Meaningful Names
```c
// Good
int studentGrades[50];
char userName[30];

// Bad
int a[50];
char b[30];
```

### 5. Handle Memory Allocation Failures
```c
int *array = malloc(size * sizeof(int));
if(array == NULL) {
    // Handle allocation failure
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
}
```

## Performance Considerations

### 1. Memory Layout
- Arrays provide excellent cache performance due to contiguous memory
- Multi-dimensional arrays benefit from row-major order access

### 2. Access Patterns
```c
// Good: Row-major access
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        matrix[i][j] = 0;  // Access by row
    }
}

// Bad: Column-major access
for(int j = 0; j < cols; j++) {
    for(int i = 0; i < rows; i++) {
        matrix[i][j] = 0;  // Access by column (poor cache performance)
    }
}
```

### 3. Dynamic vs Static Arrays
- Static arrays: Faster access, no allocation overhead
- Dynamic arrays: Flexible size, memory management overhead

### 4. Array Size Considerations
- Very large arrays may cause stack overflow (for stack allocation)
- Consider heap allocation for large arrays
- Balance between memory usage and performance

## Summary

Arrays in C are versatile data structures that come in various forms:
- **One-dimensional arrays** for simple lists
- **Multi-dimensional arrays** for tables and matrices
- **Character arrays** for string handling
- **Dynamic arrays** for runtime size determination
- **Array of pointers** for flexible data management
- **Array of structures** for complex data collections

Understanding these types, their proper usage, and common pitfalls is essential for writing robust and efficient C programs. Always remember to:
- Check array bounds
- Initialize arrays properly
- Free dynamically allocated memory
- Use appropriate array types for your use case
- Consider performance implications of access patterns
