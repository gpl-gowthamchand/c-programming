/*
 * Tutorial: Understanding Pointers in C
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Description: A comprehensive tutorial on pointers in C programming
 * 
 * Prerequisites: Basic understanding of variables and functions in C
 * 
 * Learning Objectives:
 * - Understand what pointers are and how they work
 * - Learn pointer declaration and initialization
 * - Master pointer arithmetic
 * - Understand pointer to pointer concepts
 * - Learn common pointer pitfalls and how to avoid them
 * 
 * Step 1: Basic Pointer Concepts
 * [Code for step 1]
 * 
 * Step 2: Pointer Arithmetic
 * [Code for step 2]
 * 
 * Step 3: Pointers and Arrays
 * [Code for step 3]
 * 
 * Step 4: Pointers and Functions
 * [Code for step 4]
 * 
 * Practice Exercise:
 * Create a function that swaps two integers using pointers
 * 
 * Common Mistakes:
 * - Dereferencing uninitialized pointers
 * - Using pointers after freeing memory
 * - Confusing pointer and value operations
 */

#include <stdio.h>
#include <stdlib.h>

// Step 1: Basic Pointer Concepts
void basicPointers() {
    printf("=== Step 1: Basic Pointer Concepts ===\n");
    
    int num = 42;
    int *ptr;  // Declaration of pointer
    
    ptr = &num;  // Assigning address of num to ptr
    
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    printf("Address of ptr: %p\n", &ptr);
    
    // Modifying value through pointer
    *ptr = 100;
    printf("After *ptr = 100:\n");
    printf("Value of num: %d\n", num);
    printf("Value pointed by ptr: %d\n", *ptr);
}

// Step 2: Pointer Arithmetic
void pointerArithmetic() {
    printf("\n=== Step 2: Pointer Arithmetic ===\n");
    
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // Points to first element
    
    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (address: %p)\n", i, *(ptr + i), ptr + i);
    }
    
    printf("\nPointer arithmetic operations:\n");
    printf("ptr points to: %d\n", *ptr);
    printf("ptr + 1 points to: %d\n", *(ptr + 1));
    printf("ptr + 2 points to: %d\n", *(ptr + 2));
    
    // Incrementing pointer
    ptr++;
    printf("After ptr++: %d\n", *ptr);
    ptr += 2;
    printf("After ptr += 2: %d\n", *ptr);
}

// Step 3: Pointers and Arrays
void pointersAndArrays() {
    printf("\n=== Step 3: Pointers and Arrays ===\n");
    
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("Different ways to access array elements:\n");
    printf("arr[0] = %d\n", arr[0]);
    printf("*(arr + 0) = %d\n", *(arr + 0));
    printf("ptr[0] = %d\n", ptr[0]);
    printf("*ptr = %d\n", *ptr);
    
    printf("\nArray traversal using pointers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }
}

// Step 4: Pointers and Functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pointersAndFunctions() {
    printf("\n=== Step 4: Pointers and Functions ===\n");
    
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    
    swap(&x, &y);  // Pass addresses
    
    printf("After swap: x = %d, y = %d\n", x, y);
}

// Step 5: Dynamic Memory Allocation
void dynamicMemory() {
    printf("\n=== Step 5: Dynamic Memory Allocation ===\n");
    
    int *ptr = (int*)malloc(5 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }
    
    printf("Dynamically allocated array:\n");
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    free(ptr);  // Always free allocated memory
    printf("Memory freed successfully!\n");
}

// Practice Exercise Solution
void practiceExercise() {
    printf("\n=== Practice Exercise: Swap Function ===\n");
    
    int a = 100, b = 200;
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    // Your task: Create a swap function using pointers
    swap(&a, &b);
    
    printf("After swap: a = %d, b = %d\n", a, b);
    printf("Exercise completed! ✅\n");
}

// Common Mistakes Demonstration
void commonMistakes() {
    printf("\n=== Common Mistakes to Avoid ===\n");
    
    // Mistake 1: Uninitialized pointer
    printf("1. Uninitialized pointer:\n");
    int *uninitialized_ptr;
    // *uninitialized_ptr = 10;  // DON'T DO THIS! (commented out for safety)
    printf("   Never dereference uninitialized pointers!\n");
    
    // Mistake 2: Using pointer after free
    printf("2. Using pointer after free:\n");
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    free(ptr);
    // *ptr = 10;  // DON'T DO THIS! (commented out for safety)
    printf("   Never use a pointer after freeing its memory!\n");
    
    // Mistake 3: Confusing & and *
    printf("3. Confusing & and *:\n");
    int value = 50;
    int *ptr2 = &value;
    printf("   value = %d\n", value);
    printf("   &value = %p (address)\n", &value);
    printf("   ptr2 = %p (address)\n", ptr2);
    printf("   *ptr2 = %d (value)\n", *ptr2);
}

int main() {
    printf("========================================\n");
    printf("    Pointers Tutorial in C Programming  \n");
    printf("========================================\n");
    
    basicPointers();
    pointerArithmetic();
    pointersAndArrays();
    pointersAndFunctions();
    dynamicMemory();
    practiceExercise();
    commonMistakes();
    
    printf("\n========================================\n");
    printf("    Tutorial Complete! 🎉\n");
    printf("========================================\n");
    printf("Key Takeaways:\n");
    printf("- Pointers store memory addresses\n");
    printf("- Use * to dereference (get value)\n");
    printf("- Use & to get address of variable\n");
    printf("- Always initialize pointers before use\n");
    printf("- Always free dynamically allocated memory\n");
    
    return 0;
}
