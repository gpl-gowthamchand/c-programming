# Dynamic Memory Allocation in C Programming

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](16_pointers.md) | [🏠 Home](README.md) | [➡️ Next](18_file_handling.md)

</div>

---


## Table of Contents
1. [Introduction](#introduction)
2. [Memory Management Functions](#memory-management-functions)
3. [malloc() Function](#malloc-function)
4. [calloc() Function](#calloc-function)
5. [realloc() Function](#realloc-function)
6. [free() Function](#free-function)
7. [Memory Leaks and Prevention](#memory-leaks-and-prevention)
8. [Common Pitfalls](#common-pitfalls)
9. [Best Practices](#best-practices)
10. [Practical Examples](#practical-examples)
11. [Advanced Topics](#advanced-topics)

## Introduction

Dynamic memory allocation is a fundamental concept in C programming that allows programs to allocate and deallocate memory at runtime rather than at compile time. This provides flexibility in memory management and is essential for programs that need to handle variable amounts of data.

### Why Dynamic Memory Allocation?

- **Flexibility**: Allocate memory based on runtime requirements
- **Efficiency**: Use only the memory you need
- **Scalability**: Handle varying data sizes
- **Memory Reuse**: Allocate and free memory as needed

### Memory Layout in C

```
┌─────────────────────────────────────┐
│           Stack (Local variables)   │
├─────────────────────────────────────┤
│                                     │
│           Heap (Dynamic memory)     │
│                                     │
├─────────────────────────────────────┤
│           Global variables          │
├─────────────────────────────────────┤
│           Code segment              │
└─────────────────────────────────────┘
```

## Memory Management Functions

C provides four main functions for dynamic memory management:

1. **malloc()** - Allocate memory
2. **calloc()** - Allocate and initialize memory to zero
3. **realloc()** - Resize allocated memory
4. **free()** - Deallocate memory

### Required Header

```c
#include <stdlib.h>
```

## malloc() Function

The `malloc()` function allocates a block of memory of specified size.

### Syntax

```c
void *malloc(size_t size);
```

### Parameters

- **size**: Number of bytes to allocate (size_t is an unsigned integer type)

### Return Value

- **Success**: Pointer to the allocated memory block
- **Failure**: NULL pointer

### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    
    // Allocate memory for one integer
    ptr = (int *)malloc(sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Use the allocated memory
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    
    // Free the memory
    free(ptr);
    ptr = NULL;  // Good practice
    
    return 0;
}
```

### Allocating Arrays

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory for n integers
    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    // Use array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free memory
    free(arr);
    arr = NULL;
    
    return 0;
}
```

## calloc() Function

The `calloc()` function allocates memory and initializes it to zero.

### Syntax

```c
void *calloc(size_t nmemb, size_t size);
```

### Parameters

- **nmemb**: Number of elements
- **size**: Size of each element in bytes

### Return Value

- **Success**: Pointer to the allocated memory block (initialized to zero)
- **Failure**: NULL pointer

### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    
    // Allocate memory for 5 integers, initialized to zero
    int *arr = (int *)calloc(n, sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Print values (all should be 0)
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    free(arr);
    arr = NULL;
    
    return 0;
}
```

### calloc() vs malloc()

| Feature | malloc() | calloc() |
|---------|----------|----------|
| Initialization | Uninitialized | Initialized to zero |
| Parameters | Size in bytes | Number of elements × size |
| Use case | Single allocation | Array allocation |
| Performance | Faster | Slower (due to zeroing) |

## realloc() Function

The `realloc()` function changes the size of previously allocated memory.

### Syntax

```c
void *realloc(void *ptr, size_t size);
```

### Parameters

- **ptr**: Pointer to previously allocated memory (can be NULL)
- **size**: New size in bytes

### Return Value

- **Success**: Pointer to the reallocated memory block
- **Failure**: NULL pointer (original memory remains unchanged)

### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    
    if (arr == NULL) {
        printf("Initial allocation failed!\n");
        return 1;
    }
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    // Resize to 10 elements
    int *new_arr = (int *)realloc(arr, 10 * sizeof(int));
    
    if (new_arr == NULL) {
        printf("Reallocation failed!\n");
        free(arr);  // Free original memory
        return 1;
    }
    
    arr = new_arr;  // Update pointer
    
    // Initialize new elements
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }
    
    // Print all elements
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    arr = NULL;
    
    return 0;
}
```

### Important Notes about realloc()

1. **Original pointer may change**: The returned pointer might be different from the original
2. **Data preservation**: Existing data is preserved when possible
3. **NULL handling**: If ptr is NULL, realloc() behaves like malloc()
4. **Size 0**: If size is 0, the memory is freed and NULL is returned

## free() Function

The `free()` function deallocates previously allocated memory.

### Syntax

```c
void free(void *ptr);
```

### Parameters

- **ptr**: Pointer to previously allocated memory

### Return Value

- **None** (void function)

### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    *ptr = 100;
    printf("Value before free: %d\n", *ptr);
    
    // Free the memory
    free(ptr);
    
    // Set pointer to NULL to prevent dangling pointer
    ptr = NULL;
    
    // Attempting to use freed memory is undefined behavior
    // printf("Value after free: %d\n", *ptr);  // DANGEROUS!
    
    return 0;
}
```

## Memory Leaks and Prevention

A memory leak occurs when allocated memory is not properly freed, causing the program to consume more memory over time.

### Common Causes of Memory Leaks

1. **Forgetting to call free()**
2. **Losing pointer to allocated memory**
3. **Early return without freeing memory**
4. **Exception handling without cleanup**

### Example of Memory Leak

```c
#include <stdio.h>
#include <stdlib.h>

void function_with_leak() {
    int *ptr = (int *)malloc(100 * sizeof(int));
    
    if (ptr == NULL) {
        return;  // Memory leak if allocation succeeds
    }
    
    // Use memory
    ptr[0] = 42;
    
    // Missing free(ptr) - MEMORY LEAK!
}

int main() {
    for (int i = 0; i < 1000; i++) {
        function_with_leak();  // Creates 1000 memory leaks
    }
    
    return 0;
}
```

### Prevention Techniques

```c
#include <stdio.h>
#include <stdlib.h>

void function_without_leak() {
    int *ptr = (int *)malloc(100 * sizeof(int));
    
    if (ptr == NULL) {
        return;
    }
    
    // Use memory
    ptr[0] = 42;
    
    // Always free before returning
    free(ptr);
    ptr = NULL;
}

// Alternative: Use cleanup labels
void function_with_cleanup() {
    int *ptr1 = NULL;
    int *ptr2 = NULL;
    
    ptr1 = (int *)malloc(100 * sizeof(int));
    if (ptr1 == NULL) {
        goto cleanup;
    }
    
    ptr2 = (int *)malloc(200 * sizeof(int));
    if (ptr2 == NULL) {
        goto cleanup;
    }
    
    // Use memory
    ptr1[0] = 42;
    ptr2[0] = 100;
    
cleanup:
    if (ptr1) {
        free(ptr1);
        ptr1 = NULL;
    }
    if (ptr2) {
        free(ptr2);
        ptr2 = NULL;
    }
}
```

## Common Pitfalls

### 1. Dangling Pointers

```c
int *ptr = (int *)malloc(sizeof(int));
free(ptr);
// ptr now points to freed memory - DANGEROUS!
*ptr = 42;  // Undefined behavior

// Solution: Set to NULL after freeing
free(ptr);
ptr = NULL;
```

### 2. Double Free

```c
int *ptr = (int *)malloc(sizeof(int));
free(ptr);
free(ptr);  // Double free - Undefined behavior!

// Solution: Set to NULL after freeing
free(ptr);
ptr = NULL;
// Now free(ptr) is safe (free(NULL) does nothing)
```

### 3. Memory Alignment Issues

```c
// Incorrect: May cause alignment issues
char *ptr = (char *)malloc(1);
int *int_ptr = (int *)ptr;  // Potential alignment problem

// Correct: Allocate with proper alignment
int *int_ptr = (int *)malloc(sizeof(int));
```

### 4. Buffer Overflow

```c
int *arr = (int *)malloc(5 * sizeof(int));
arr[5] = 42;  // Buffer overflow - accessing beyond allocated memory

// Solution: Always check bounds
if (index < 5) {
    arr[index] = 42;
}
```

## Best Practices

### 1. Always Check Return Values

```c
int *ptr = (int *)malloc(sizeof(int));
if (ptr == NULL) {
    // Handle allocation failure
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
}
```

### 2. Use sizeof() for Portability

```c
// Good
int *ptr = (int *)malloc(10 * sizeof(int));

// Bad - not portable
int *ptr = (int *)malloc(40);  // Assumes int is 4 bytes
```

### 3. Initialize Pointers to NULL

```c
int *ptr = NULL;  // Good practice
```

### 4. Free Memory in Reverse Order

```c
int *ptr1 = (int *)malloc(sizeof(int));
int *ptr2 = (int *)malloc(sizeof(int));

// Free in reverse order (if they depend on each other)
free(ptr2);
free(ptr1);
```

### 5. Use const for Read-only Data

```c
const int *ptr = (const int *)malloc(10 * sizeof(int));
// ptr points to read-only data
```

## Practical Examples

### 1. Dynamic String Handling

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_string(const char* source) {
    if (source == NULL) {
        return NULL;
    }
    
    size_t len = strlen(source);
    char* new_string = (char*)malloc((len + 1) * sizeof(char));
    
    if (new_string == NULL) {
        return NULL;
    }
    
    strcpy(new_string, source);
    return new_string;
}

int main() {
    char* str = create_string("Hello, World!");
    
    if (str != NULL) {
        printf("String: %s\n", str);
        free(str);
        str = NULL;
    }
    
    return 0;
}
```

### 2. Dynamic 2D Array

```c
#include <stdio.h>
#include <stdlib.h>

int** create_2d_array(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    
    if (arr == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            // Clean up previously allocated rows
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
    }
    
    return arr;
}

void free_2d_array(int** arr, int rows) {
    if (arr != NULL) {
        for (int i = 0; i < rows; i++) {
            free(arr[i]);
        }
        free(arr);
    }
}

int main() {
    int rows = 3, cols = 4;
    int** arr = create_2d_array(rows, cols);
    
    if (arr != NULL) {
        // Initialize array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = i * cols + j;
            }
        }
        
        // Print array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%2d ", arr[i][j]);
            }
            printf("\n");
        }
        
        free_2d_array(arr, rows);
        arr = NULL;
    }
    
    return 0;
}
```

### 3. Dynamic Linked List

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    
    print_list(head);
    
    free_list(head);
    head = NULL;
    
    return 0;
}
```

## Advanced Topics

### 1. Memory Pools

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024
#define BLOCK_SIZE 64

typedef struct MemoryPool {
    char pool[POOL_SIZE];
    int used;
} MemoryPool;

void* pool_alloc(MemoryPool* pool, size_t size) {
    if (pool->used + size > POOL_SIZE) {
        return NULL;  // Pool is full
    }
    
    void* ptr = &pool->pool[pool->used];
    pool->used += size;
    return ptr;
}

void pool_reset(MemoryPool* pool) {
    pool->used = 0;
}

int main() {
    MemoryPool pool = {0};
    
    char* str1 = (char*)pool_alloc(&pool, 20);
    char* str2 = (char*)pool_alloc(&pool, 30);
    
    if (str1 && str2) {
        strcpy(str1, "Hello");
        strcpy(str2, "World");
        printf("%s %s\n", str1, str2);
    }
    
    pool_reset(&pool);
    
    return 0;
}
```

### 2. Custom Memory Allocator

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    int free;
    struct Block* next;
} Block;

typedef struct {
    Block* head;
    size_t total_size;
    size_t used_size;
} CustomAllocator;

CustomAllocator* create_allocator(size_t size) {
    CustomAllocator* allocator = (CustomAllocator*)malloc(sizeof(CustomAllocator));
    if (!allocator) return NULL;
    
    allocator->head = (Block*)malloc(size);
    if (!allocator->head) {
        free(allocator);
        return NULL;
    }
    
    allocator->head->size = size - sizeof(Block);
    allocator->head->free = 1;
    allocator->head->next = NULL;
    allocator->total_size = size;
    allocator->used_size = sizeof(Block);
    
    return allocator;
}

void* custom_malloc(CustomAllocator* allocator, size_t size) {
    Block* current = allocator->head;
    
    while (current) {
        if (current->free && current->size >= size) {
            if (current->size > size + sizeof(Block)) {
                // Split block
                Block* new_block = (Block*)((char*)current + sizeof(Block) + size);
                new_block->size = current->size - size - sizeof(Block);
                new_block->free = 1;
                new_block->next = current->next;
                
                current->size = size;
                current->next = new_block;
            }
            
            current->free = 0;
            allocator->used_size += size;
            return (char*)current + sizeof(Block);
        }
        current = current->next;
    }
    
    return NULL;  // No suitable block found
}

void custom_free(CustomAllocator* allocator, void* ptr) {
    if (!ptr) return;
    
    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block->free = 1;
    allocator->used_size -= block->size;
    
    // Merge with next free block
    if (block->next && block->next->free) {
        block->size += sizeof(Block) + block->next->size;
        block->next = block->next->next;
    }
}

void destroy_allocator(CustomAllocator* allocator) {
    if (allocator) {
        free(allocator->head);
        free(allocator);
    }
}

int main() {
    CustomAllocator* allocator = create_allocator(1024);
    
    if (allocator) {
        char* str1 = (char*)custom_malloc(allocator, 20);
        char* str2 = (char*)custom_malloc(allocator, 30);
        
        if (str1 && str2) {
            strcpy(str1, "Hello");
            strcpy(str2, "World");
            printf("%s %s\n", str1, str2);
            
            custom_free(allocator, str1);
            custom_free(allocator, str2);
        }
        
        destroy_allocator(allocator);
    }
    
    return 0;
}
```

## Summary

Dynamic memory allocation is a powerful feature in C that provides flexibility and efficiency in memory management. Key points to remember:

1. **Always check return values** from allocation functions
2. **Free memory** when no longer needed
3. **Set pointers to NULL** after freeing
4. **Use appropriate functions** for different needs:
   - `malloc()` for simple allocation
   - `calloc()` for array allocation with zero initialization
   - `realloc()` for resizing memory
   - `free()` for deallocation
5. **Avoid common pitfalls** like memory leaks, dangling pointers, and double free
6. **Follow best practices** for robust and maintainable code

Mastering dynamic memory allocation is essential for writing efficient and scalable C programs. Practice with the examples provided and always remember to manage memory responsibly.


---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](16_pointers.md) | [🏠 Home](README.md) | [➡️ Next](18_file_handling.md)

</div>