# Pattern Programs in C

Pattern programs are commonly used to practice loops and understand control flow in C.  
They help visualize how nested loops work and how output can be formatted.

## 1. Star Triangle Pattern

**Code:**
```c
#include <stdio.h>

int main() {
    int rows = 5;
    // Outer loop for each row
    for (int i = 1; i <= rows; i++) {
        // Inner loop for printing stars in each row
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n"); // Move to next line after each row
    }
    return 0;
}
```

**Explanation:**  
- The outer loop (`i`) controls the number of rows.
- The inner loop (`j`) prints stars equal to the current row number.
- After printing stars for a row, a newline is printed.

**Output:**
```
* 
* * 
* * * 
* * * * 
* * * * * 
```

---

## 2. Number Pyramid Pattern

**Code:**
```c
#include <stdio.h>

int main() {
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        // Print spaces for pyramid shape
        for (int s = 1; s <= rows - i; s++) {
            printf("  ");
        }
        // Print numbers
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
```

**Explanation:**  
- Spaces are printed before numbers to create the pyramid shape.
- Numbers from 1 to the current row number are printed in each row.

**Output:**
```
        1 
      1 2 
    1 2 3 
  1 2 3 4 
1 2 3 4 5 
```

---

## 3. Inverted Star Pattern

**Code:**
```c
#include <stdio.h>

int main() {
    int rows = 5;
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
```

**Explanation:**  
- Starts with the maximum number of stars and decreases each row.

**Output:**
```
* * * * * 
* * * * 
* * * 
* * 
* 
```

---

## Summary

- Pattern programs use nested loops for rows and columns.
- They are useful for practicing logic, loops, and output formatting in C.
- Try modifying the code to create your