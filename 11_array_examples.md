# Examples of Arrays in C Programming

## 🧭 **Navigation**
| ⬅️ Previous | 🏠 Home | ➡️ Next |
|:------------|:--------|:--------|
| [10 Types Of Arrays](10_types_of_arrays.md) | [README](README.md) | [12 Strings](12_strings.md) |

---

This document contains various practical examples demonstrating array operations in C programming.

## Basic Array Operations

### 1. Finding the Largest Element
```c
#include <stdio.h>
int main() {
    int arr[5] = {2, 10, 5, 1, 7};
    int max = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Largest = %d", max);
    return 0;
}
```

### 2. Calculating Sum of Elements
```c
int sum = 0;
for (int i = 0; i < 5; i++) {
    sum += arr[i];
}
printf("Sum = %d", sum);
```

### 3. Reversing an Array
```c
#include <stdio.h>
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

### 4. Counting Even/Odd Elements
```c
int even = 0, odd = 0;
for (int i = 0; i < 5; i++) {
    if (arr[i] % 2 == 0) even++;
    else odd++;
}
printf("Even: %d, Odd: %d", even, odd);
```

### 5. Size of Array in Bytes
```c
int arr[5];
printf("Size in bytes = %lu\n", sizeof(arr));
printf("Number of elements = %lu\n", sizeof(arr)/sizeof(arr[0]));
```
**Note:** If int = 4 bytes, total size = 5 * 4 = 20 bytes.

## User-Requested Examples

### 6. Take 5 integers into an array and print the smallest number
```c
#include <stdio.h>
int main() {
    int arr[5];
    int min;
    
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    
    min = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    printf("Smallest number: %d\n", min);
    return 0;
}
```

### 7. Input 5 numbers and reverse print them
```c
#include <stdio.h>
int main() {
    int arr[5];
    
    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Numbers in reverse order: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### 8. Count positive, negative, and zero in array of 10
```c
#include <stdio.h>
int main() {
    int arr[10];
    int positive = 0, negative = 0, zero = 0;
    
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > 0) positive++;
        else if (arr[i] < 0) negative++;
        else zero++;
    }
    
    printf("Positive: %d, Negative: %d, Zero: %d\n", positive, negative, zero);
    return 0;
}
```

### 9. Search for an element in an array (linear search)
```c
#include <stdio.h>
int main() {
    int arr[10] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    int search, found = -1;
    
    printf("Enter element to search: ");
    scanf("%d", &search);
    
    for (int i = 0; i < 10; i++) {
        if (arr[i] == search) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        printf("Element found at index %d\n", found);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
```

### 10. Program to take 5 integers and print largest and smallest element
```c
#include <stdio.h>
int main() {
    int arr[5];
    int max, min;
    
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    
    max = min = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    printf("Largest: %d, Smallest: %d\n", max, min);
    return 0;
}
```

### 11. Finding max and min in a single loop
```c
#include <stdio.h>
int main() {
    int arr[10] = {23, 45, 12, 67, 89, 34, 56, 78, 90, 1};
    int max = arr[0], min = arr[0];
    
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    return 0;
}
```

### 12. Reverse Array In-Place

**Concept**

To reverse an array, we swap the first and last elements, then the second and second-last, and so on until the middle.

**Example:**

Original:  [1, 2, 3, 4, 5]
Reversed:  [5, 4, 3, 2, 1]

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int i, temp;
    int n = 5;

    // Reverse using swap
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    // Print reversed array
    printf("Reversed Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

**Key Points**

- We run the loop till n/2 because swapping beyond the middle would undo the reverse.
- Time complexity: O(n).
- Space complexity: O(1) (no extra array used).

### 13. What is Bubble Sort?

**Concept**

It repeatedly compares adjacent elements and swaps them if they are in the wrong order.

After each pass, the largest element "bubbles" to the end of the array.

We repeat this process for all elements until the array is sorted.

**Example Walkthrough**

Sort [5, 2, 4, 1] in ascending order:

**Pass 1:**
- Compare 5 and 2 → swap → [2, 5, 4, 1]
- Compare 5 and 4 → swap → [2, 4, 5, 1]
- Compare 5 and 1 → swap → [2, 4, 1, 5]

**Pass 2:**
- Compare 2 and 4 → no swap → [2, 4, 1, 5]
- Compare 4 and 1 → swap → [2, 1, 4, 5]

**Pass 3:**
- Compare 2 and 1 → swap → [1, 2, 4, 5]

Now sorted.

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[5] = {5, 2, 4, 1, 3};
    int n = 5;
    int i, j, temp;

    // Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

**Key Points**

- Time complexity: O(n²) in worst case.
- Best case: O(n) (if array is already sorted, with optimization).
- Space complexity: O(1) (in-place sorting).

## Additional Useful Examples

### 14. Finding Second Largest Element
```c
#include <stdio.h>
int main() {
    int arr[6] = {12, 35, 1, 10, 34, 1};
    int first, second;
    
    if (arr[0] > arr[1]) {
        first = arr[0];
        second = arr[1];
    } else {
        first = arr[1];
        second = arr[0];
    }
    
    for (int i = 2; i < 6; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    
    printf("Second largest: %d\n", second);
    return 0;
}
```

### 15. Removing Duplicates from Array
```c
#include <stdio.h>
int main() {
    int arr[8] = {1, 2, 2, 3, 4, 4, 5, 5};
    int n = 8;
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Remove duplicates
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    
    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### 16. Array Rotation
```c
#include <stdio.h>
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int temp, n = 5, d = 2; // Rotate by 2 positions
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Rotate array
    for (int i = 0; i < d; i++) {
        temp = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
    
    printf("\nRotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### 17. Finding Missing Number in Array
```c
#include <stdio.h>
int main() {
    int arr[9] = {1, 2, 4, 6, 3, 7, 8, 9, 10}; // Missing 5
    int n = 10; // Expected range 1 to 10
    int sum = 0, expected_sum;
    
    for (int i = 0; i < 9; i++) {
        sum += arr[i];
    }
    
    expected_sum = (n * (n + 1)) / 2;
    printf("Missing number: %d\n", expected_sum - sum);
    return 0;
}
```

### 18. Array Frequency Count
```c
#include <stdio.h>
int main() {
    int arr[10] = {1, 2, 3, 1, 2, 1, 3, 4, 2, 1};
    int freq[100] = {0}; // Assuming elements are 0-99
    
    for (int i = 0; i < 10; i++) {
        freq[arr[i]]++;
    }
    
    printf("Element frequencies:\n");
    for (int i = 0; i < 100; i++) {
        if (freq[i] > 0) {
            printf("%d appears %d times\n", i, freq[i]);
        }
    }
    return 0;
}
```

## Key Points to Remember

1. **Array indexing starts from 0**
2. **Always check array bounds to avoid segmentation faults**
3. **Use sizeof() to get array size in bytes**
4. **Arrays are passed by reference to functions**
5. **Multi-dimensional arrays can be thought of as arrays of arrays**
6. **Dynamic memory allocation is needed for variable-sized arrays**

## Common Pitfalls

- **Off-by-one errors** in loop conditions
- **Forgetting to initialize arrays**
- **Accessing elements beyond array bounds**
- **Not handling edge cases (empty arrays, single elements)**
- **Memory leaks when using dynamic arrays**

These examples cover most common array operations and should help you understand how to work with arrays effectively in C programming.

## 2D Array Examples

### 19. Sum of All Elements in 2D Array

**Concept**
To find the sum of all elements in a 2D array, we need to iterate through each row and column, adding each element to a running total.

**How It Works**
- Use nested loops: outer loop for rows, inner loop for columns
- Initialize a sum variable to 0
- Add each element to the sum as we traverse the array

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rows = 3, cols = 3;
    int sum = 0;
    
    // Calculate sum of all elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    
    printf("Sum of all elements: %d\n", sum);
    return 0;
}
```

**Output:** Sum of all elements: 45

---

### 20. Sum of Each Row & Column

**Concept**
Calculate the sum of elements in each row separately and each column separately. This helps understand the distribution of values across the matrix.

**How It Works**
- For row sums: iterate through each row, sum elements in that row
- For column sums: iterate through each column, sum elements in that column
- Store results in separate arrays for row sums and column sums

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rows = 3, cols = 3;
    int rowSum[3] = {0}, colSum[3] = {0};
    
    // Calculate row sums
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += arr[i][j];
        }
    }
    
    // Calculate column sums
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            colSum[j] += arr[i][j];
        }
    }
    
    // Print row sums
    printf("Row sums:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d\n", i+1, rowSum[i]);
    }
    
    // Print column sums
    printf("\nColumn sums:\n");
    for (int j = 0; j < cols; j++) {
        printf("Column %d: %d\n", j+1, colSum[j]);
    }
    
    return 0;
}
```

**Output:**
```
Row sums:
Row 1: 6
Row 2: 15
Row 3: 24

Column sums:
Column 1: 12
Column 2: 15
Column 3: 18
```

---

### 21. Transpose of a Matrix

**Concept**
The transpose of a matrix is obtained by interchanging rows and columns. If the original matrix is m×n, the transpose will be n×m.

**How It Works**
- Create a new matrix with swapped dimensions
- Copy elements from position [i][j] to position [j][i]
- This effectively flips the matrix over its main diagonal

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int rows = 2, cols = 3;
    int transpose[3][2];
    
    // Calculate transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = arr[i][j];
        }
    }
    
    // Print original matrix
    printf("Original Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // Print transpose matrix
    printf("\nTranspose Matrix (%dx%d):\n", cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

**Output:**
```
Original Matrix (2x3):
1 2 3
4 5 6

Transpose Matrix (3x2):
1 4
2 5
3 6
```

---

### 24. In-Place Transpose (Square Matrix)

**Concept**
In-place transpose modifies the original matrix without creating a new one. This is only possible for square matrices (n×n) and requires careful swapping to avoid double-swapping elements.

**How It Works**
- Only swap elements above the main diagonal with elements below it
- Use j = i + 1 to ensure we don't swap elements twice
- This approach saves memory but only works for square matrices

**Why j = i + 1?**
If we swap for all i and j, we end up swapping back. The i+1 ensures we only swap the upper triangle with the lower triangle once.

**Code Example**
```c
#include <stdio.h>
int main() {
    int i, j, temp;
    int matrix[3][3];

    // Input
    printf("Enter 9 elements for 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Print original matrix
    printf("Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // In-place transpose
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {  // only swap elements above diagonal
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Print transpose matrix
    printf("Transpose matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

**Sample Input/Output:**
```
Enter 9 elements for 3x3 matrix:
1 2 3
4 5 6
7 8 9

Matrix:
1 2 3
4 5 6
7 8 9

Transpose matrix:
1 4 7
2 5 8
3 6 9
```

**Key Points:**
- **Memory Efficient**: Uses O(1) extra space instead of O(n²)
- **Square Matrix Only**: Works only for n×n matrices
- **Smart Swapping**: j = i + 1 prevents double-swapping
- **Diagonal Elements**: Stay in place (no swapping needed)

---

## Multi-Dimensional Array Examples

### 25. 3D Array Basics and Traversal

**Concept**
3D arrays can be visualized as a cube or multiple 2D matrices stacked on top of each other. They are useful for representing 3D space, time-series data, or complex data structures.

**How It Works**
- 3D arrays have three dimensions: depth, rows, and columns
- Memory is allocated in row-major order
- Use three nested loops for traversal: depth → rows → columns

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[2][3][4] = {
        {{1, 2, 3, 4},     // First 2D matrix
         {5, 6, 7, 8},
         {9, 10, 11, 12}},
        {{13, 14, 15, 16}, // Second 2D matrix
         {17, 18, 19, 20},
         {21, 22, 23, 24}}
    };
    
    int depth = 2, rows = 3, cols = 4;
    
    // Traverse and print 3D array
    printf("3D Array Elements:\n");
    for (int d = 0; d < depth; d++) {
        printf("Layer %d:\n", d + 1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%2d ", arr[d][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
```

**Output:**
```
3D Array Elements:
Layer 1:
 1  2  3  4
 5  6  7  8
 9 10 11 12

Layer 2:
13 14 15 16
17 18 19 20
21 22 23 24
```

---

### 26. Sum of 3D Array Elements

**Concept**
Calculate the sum of all elements in a 3D array by traversing through all three dimensions and accumulating the values.

**How It Works**
- Initialize a sum variable to 0
- Use three nested loops to access each element
- Add each element to the running total

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[2][2][3] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };
    
    int depth = 2, rows = 2, cols = 3;
    int sum = 0;
    
    // Calculate sum of all elements
    for (int d = 0; d < depth; d++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += arr[d][i][j];
            }
        }
    }
    
    printf("Sum of all elements: %d\n", sum);
    printf("Total elements: %d\n", depth * rows * cols);
    printf("Average: %.2f\n", (float)sum / (depth * rows * cols));
    
    return 0;
}
```

**Output:**
```
Sum of all elements: 78
Total elements: 12
Average: 6.50
```

---

### 27. Finding Maximum and Minimum in 3D Array

**Concept**
Find the largest and smallest values in a 3D array by comparing each element with the current maximum and minimum values.

**How It Works**
- Initialize max and min with the first element
- Traverse through all dimensions comparing each element
- Update max and min when larger/smaller values are found

**Code Example**
```c
#include <stdio.h>
#include <limits.h>

int main() {
    int arr[3][2][2] = {
        {{15, 23}, {8, 31}},
        {{12, 19}, {25, 7}},
        {{9, 14}, {18, 22}}
    };
    
    int depth = 3, rows = 2, cols = 2;
    int max = INT_MIN, min = INT_MAX;
    int max_pos[3], min_pos[3]; // Store positions
    
    // Find max and min
    for (int d = 0; d < depth; d++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[d][i][j] > max) {
                    max = arr[d][i][j];
                    max_pos[0] = d; max_pos[1] = i; max_pos[2] = j;
                }
                if (arr[d][i][j] < min) {
                    min = arr[d][i][j];
                    min_pos[0] = d; min_pos[1] = i; min_pos[2] = j;
                }
            }
        }
    }
    
    printf("Maximum: %d at position [%d][%d][%d]\n", 
           max, max_pos[0], max_pos[1], max_pos[2]);
    printf("Minimum: %d at position [%d][%d][%d]\n", 
           min, min_pos[0], min_pos[1], min_pos[2]);
    
    return 0;
}
```

**Output:**
```
Maximum: 31 at position [0][1][1]
Minimum: 7 at position [1][1][1]
```

---

### 28. 3D Array Rotation (Layer by Layer)

**Concept**
Rotate each 2D layer of a 3D array independently. This is useful for 3D transformations, image processing, or data manipulation.

**How It Works**
- Treat each depth layer as a separate 2D matrix
- Apply rotation algorithm to each layer
- Can rotate clockwise, counterclockwise, or by specific angles

**Code Example**
```c
#include <stdio.h>

int main() {
    int arr[2][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}
    };
    
    int depth = 2, rows = 3, cols = 3;
    int rotated[2][3][3];
    
    // Rotate each layer 90 degrees clockwise
    for (int d = 0; d < depth; d++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[d][j][rows-1-i] = arr[d][i][j];
            }
        }
    }
    
    // Print original array
    printf("Original 3D Array:\n");
    for (int d = 0; d < depth; d++) {
        printf("Layer %d:\n", d + 1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%2d ", arr[d][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Print rotated array
    printf("Rotated 3D Array (90° clockwise):\n");
    for (int d = 0; d < depth; d++) {
        printf("Layer %d:\n", d + 1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%2d ", rotated[d][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
```

**Output:**
```
Original 3D Array:
Layer 1:
 1  2  3
 4  5  6
 7  8  9

Layer 2:
10 11 12
13 14 15
16 17 18

Rotated 3D Array (90° clockwise):
Layer 1:
 7  4  1
 8  5  2
 9  6  3

Layer 2:
16 13 10
17 14 11
18 15 12
```

---

### 29. 4D Array Example (Time-Series Data)

**Concept**
4D arrays can represent data with four dimensions, such as time-series data, multiple 3D objects, or complex scientific data.

**How It Works**
- 4D arrays have four dimensions: time, depth, rows, columns
- Useful for storing data that changes over time
- Memory allocation follows the same row-major pattern

**Code Example**
```c
#include <stdio.h>

int main() {
    // 4D array: [time][depth][rows][columns]
    int data[3][2][2][2] = {
        {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},     // Time 0
        {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}, // Time 1
        {{{17, 18}, {19, 20}}, {{21, 22}, {23, 24}}} // Time 2
    };
    
    int time = 3, depth = 2, rows = 2, cols = 2;
    
    // Print 4D array structure
    printf("4D Array Structure:\n");
    for (int t = 0; t < time; t++) {
        printf("Time %d:\n", t);
        for (int d = 0; d < depth; d++) {
            printf("  Layer %d:\n", d + 1);
            for (int i = 0; i < rows; i++) {
                printf("    ");
                for (int j = 0; j < cols; j++) {
                    printf("%2d ", data[t][d][i][j]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    
    // Calculate sum for each time period
    printf("Sum for each time period:\n");
    for (int t = 0; t < time; t++) {
        int sum = 0;
        for (int d = 0; d < depth; d++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    sum += data[t][d][i][j];
                }
            }
        }
        printf("Time %d: %d\n", t, sum);
    }
    
    return 0;
}
```

**Output:**
```
4D Array Structure:
Time 0:
  Layer 1:
     1  2
     3  4
  Layer 2:
     5  6
     7  8

Time 1:
  Layer 1:
     9 10
    11 12
  Layer 2:
    13 14
    15 16

Time 2:
  Layer 1:
    17 18
    19 20
  Layer 2:
    21 22
    23 24

Sum for each time period:
Time 0: 36
Time 1: 100
Time 2: 164
```

---

### 30. Dynamic Multi-Dimensional Array

**Concept**
Create multi-dimensional arrays dynamically using pointers and malloc. This allows for variable-sized arrays and more flexible memory management.

**How It Works**
- Use pointer arithmetic to create multi-dimensional arrays
- Allocate memory for each dimension dynamically
- Free memory properly to avoid memory leaks

**Code Example**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int depth = 3, rows = 4, cols = 5;
    
    // Allocate 3D array dynamically
    int ***arr = (int ***)malloc(depth * sizeof(int **));
    for (int d = 0; d < depth; d++) {
        arr[d] = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            arr[d][i] = (int *)malloc(cols * sizeof(int));
        }
    }
    
    // Initialize with values
    int value = 1;
    for (int d = 0; d < depth; d++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[d][i][j] = value++;
            }
        }
    }
    
    // Print the array
    printf("Dynamic 3D Array:\n");
    for (int d = 0; d < depth; d++) {
        printf("Layer %d:\n", d + 1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%3d ", arr[d][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Free memory (important!)
    for (int d = 0; d < depth; d++) {
        for (int i = 0; i < rows; i++) {
            free(arr[d][i]);
        }
        free(arr[d]);
    }
    free(arr);
    
    printf("Memory freed successfully!\n");
    return 0;
}
```

**Output:**
```
Dynamic 3D Array:
Layer 1:
  1   2   3   4   5
  6   7   8   9  10
 11  12  13  14  15
 16  17  18  19  20

Layer 2:
 21  22  23  24  25
 26  27  28  29  30
 31  32  33  34  35
 36  37  38  39  40

Layer 3:
 41  42  43  44  45
 46  47  48  49  50
 51  52  53  54  55
 56  57  58  59  60

Memory freed successfully!
```

## Key Points for Multi-Dimensional Arrays

1. **Memory Layout**: Multi-dimensional arrays are stored in row-major order
2. **Indexing**: Use multiple indices: arr[depth][row][column]
3. **Memory Management**: Dynamic allocation requires careful memory management
4. **Performance**: Cache performance decreases with more dimensions
5. **Visualization**: 3D arrays can be thought of as layers of 2D matrices
6. **Applications**: Useful for 3D graphics, scientific computing, and data analysis

---

### 22. Addition of Two Matrices

**Concept**
Matrix addition is performed by adding corresponding elements from two matrices of the same dimensions. The result is a matrix of the same size.

**How It Works**
- Check if both matrices have the same dimensions
- Create a result matrix of the same size
- Add corresponding elements: result[i][j] = matrix1[i][j] + matrix2[i][j]

**Code Example**
```c
#include <stdio.h>

int main() {
    int matrix1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int matrix2[2][3] = {
        {7, 8, 9},
        {10, 11, 12}
    };
    int result[2][3];
    int rows = 2, cols = 3;
    
    // Add matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Print first matrix
    printf("Matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    
    // Print second matrix
    printf("\nMatrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    // Print result matrix
    printf("\nResult (Matrix 1 + Matrix 2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

**Output:**
```
Matrix 1:
1 2 3
4 5 6

Matrix 2:
7 8 9
10 11 12

Result (Matrix 1 + Matrix 2):
8 10 12
14 16 18
```

---

### 23. Multiplication of Two Matrices

**Concept**
Matrix multiplication is more complex than addition. For matrices A(m×n) and B(n×p), the result C(m×p) is calculated using the dot product of rows and columns.

**How It Works**
- For each element C[i][j], multiply row i of matrix A with column j of matrix B
- Sum up all the products: C[i][j] = Σ(A[i][k] × B[k][j]) for k = 0 to n-1
- The number of columns in first matrix must equal rows in second matrix

**Code Example**
```c
#include <stdio.h>

int main() {
    int matrix1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int matrix2[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    int result[2][2];
    int rows1 = 2, cols1 = 3, cols2 = 2;
    
    // Initialize result matrix with zeros
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Multiply matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Print first matrix
    printf("Matrix 1 (2x3):\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    
    // Print second matrix
    printf("\nMatrix 2 (3x2):\n");
    for (int i = 0; i < cols1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    // Print result matrix
    printf("\nResult (Matrix 1 × Matrix 2):\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

**Output:**
```
Matrix 1 (2x3):
1 2 3
4 5 6

Matrix 2 (3x2):
7 8
9 10
11 12

Result (Matrix 1 × Matrix 2):
58 64
139 154
```

**How Matrix Multiplication Works:**
- C[0][0] = (1×7) + (2×9) + (3×11) = 7 + 18 + 33 = 58
- C[0][1] = (1×8) + (2×10) + (3×12) = 8 + 20 + 36 = 64
- C[1][0] = (4×7) + (5×9) + (6×11) = 28 + 45 + 66 = 139
- C[1][1] = (4×8) + (5×10) + (6×12) = 32 + 50 + 72 = 154

## Key Points for 2D Arrays

1. **Memory Layout**: 2D arrays are stored in row-major order in memory
2. **Indexing**: Use arr[row][column] notation
3. **Bounds Checking**: Always verify array dimensions before operations
4. **Matrix Operations**: Ensure compatible dimensions for operations
5. **Performance**: Matrix multiplication has O(n³) complexity for n×n matrices
