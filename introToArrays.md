# Introduction to Arrays in C

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

## Summary

- Arrays store multiple values of the same type.
- Indexing starts from 0.
- Size is fixed at declaration.
- Access elements using their index.
- Use loops for processing arrays.

Arrays are essential for handling collections of data efficiently in