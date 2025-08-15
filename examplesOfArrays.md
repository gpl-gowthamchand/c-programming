# Examples of Arrays in C Programming

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

### 12. Reversing array in-place (swap method)
```c
#include <stdio.h>
int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int temp;
    
    printf("Original array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    
    // Reverse in-place
    for (int i = 0; i < 6/2; i++) {
        temp = arr[i];
        arr[i] = arr[5-i];
        arr[5-i] = temp;
    }
    
    printf("\nReversed array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

### 13. Sorting array (basic bubble sort)
```c
#include <stdio.h>
int main() {
    int arr[5] = {64, 34, 25, 12, 22};
    int temp;
    
    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    // Bubble sort
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("\nSorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

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
