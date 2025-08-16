# Introduction to Arrays in C

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](08_functions.md) | [🏠 Home](README.md) | [➡️ Next](10_types_of_arrays.md)

</div>

---


Arrays are a fundamental data structure in C that allow you to store multiple values of the same type in a single variable.  
They are useful for managing lists, collections, and sequences of data.

---

## What is an Array?

An array is a collection of elements, all of the same data type, stored in contiguous memory locations.  
Each element can be accessed using its index (position in the array).

**Syntax:**
```c
data_type array_name[size];
```

**Example:**
```c
int numbers[5]; // declares an array of 5 integers
```

---

## Indexing in Arrays

- Array indices start from **0**.
- The first element is at index `0`, the second at `1`, and so on.
- For an array of size `n`, valid indices are `0` to `n-1`.

**Example:**
```c
int arr[3] = {10, 20, 30};
printf("%d", arr[0]); // prints 10
printf("%d", arr[2]); // prints 30
```

---

## Array Size

- The size of an array is fixed when it is declared.
- You cannot change the size of an array after its creation.

**Example:**
```c
float marks[10]; // array to store 10 float values
```

---

## Accessing Array Elements

- Use the index to read or modify elements.

**Example:**
```c
int nums[4];
nums[0] = 5;      // assign value to first element
nums[1] = 10;
nums[2] = 15;
nums[3] = 20;

printf("%d", nums[2]); // prints 15
```

---

## Initializing Arrays

- You can initialize arrays at the time of declaration.

**Example:**
```c
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
```

- If you provide fewer values, the remaining elements are set to zero (for numeric types).

**Example:**
```c
int arr[5] = {1, 2}; // arr[2], arr[3], arr[4] will be 0
```

---

## Looping Through Arrays

- Use loops to access or modify all elements.

**Example:**
```c
int scores[5] = {90, 85, 78, 92, 88};
for (int i = 0; i < 5; i++) {
    printf("Score %d: %d\n", i + 1, scores[i]);
}
```

---

## Common Mistakes and Errors in Arrays

1. **Accessing Out-of-Bounds Index**
   ```c
   int arr[3] = {1, 2, 3};
   printf("%d", arr[3]); // Error: valid indices are 0, 1, 2
   ```
   *Accessing an index outside the array size leads to undefined behavior.*

2. **Uninitialized Array Elements**
   ```c
   int arr[5];
   printf("%d", arr[2]); // May print garbage value if not initialized
   ```
   *Always initialize arrays before use.*

3. **Wrong Array Size**
   ```c
   int arr[2] = {1, 2, 3}; // Warning: too many initializers
   ```
   *Number of initializers should not exceed the declared size.*

4. **Using Variable as Array Size (before C99)**
   ```c
   int n = 5;
   int arr[n]; // Error in C89, allowed in C99 and later
   ```
   *Use constant size for arrays in older C standards.*

5. **Forgetting Index Starts at 0**
   ```c
   int arr[5];
   arr[5] = 10; // Error: last valid index is 4
   ```

6. **Mixing Data Types**
   ```c
   int arr[3] = {1, 'a', 2.5}; // All elements should be of the same type
   ```

---

## Types of Arrays

1. **One-Dimensional Arrays**  
   - Stores a list of elements in a single row.
   - Example: `int arr[5];`

2. **Two-Dimensional Arrays**  
   - Stores elements in a table (rows and columns), like a matrix.
   - Example: `int matrix[3][4];`

3. **Multi-Dimensional Arrays**  
   - Arrays with more than two dimensions, used for complex data structures.
   - Example: `int cube[2][3][4];`

---

## Summary

- Arrays store multiple values of the same type.
- Indexing starts from 0.
- Size is fixed at declaration.
- Access elements using their index.
- Use loops for processing arrays.
- Avoid common mistakes like out-of-bounds access and uninitialized elements.

Arrays are essential for efficiently handling collections of data in C programming.

---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](08_functions.md) | [🏠 Home](README.md) | [➡️ Next](10_types_of_arrays.md)

</div>