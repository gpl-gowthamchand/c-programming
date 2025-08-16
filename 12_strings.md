# Strings in C Programming

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](11_array_examples.md) | [🏠 Home](README.md) | [➡️ Next](13_structures.md)

</div>

---


## What is a String?

A string in C is a sequence of characters terminated by a null character (`\0`). It's essentially an array of characters where the last element is the null terminator.

**Example:**
```c
char name[] = "Gowtham";
```

**Storage in Memory:**
```
Index:  0  1  2  3  4  5  6  7
Char:   G  o  w  t  h  a  m  \0
```

## Declaring and Using Strings

### Method 1: Character Array with String Literal
```c
char str1[] = "Hello World";
char str2[20] = "Programming";
```

### Method 2: Character Array with Individual Characters
```c
char str3[] = {'H', 'e', 'l', 'l', 'o', '\0'};
char str4[10] = {'C', 'P', 'r', 'o', 'g', '\0'};
```

### Method 3: Character Pointer
```c
char *str5 = "String Literal";
```

**⚠️ IMPORTANT: String Literals vs Character Arrays**

There's a crucial difference between string literals and character arrays that affects whether you can modify them:

#### String Literals (Read-Only)
```c
char *str_literal = "Hello World";  // String literal - stored in read-only memory
// str_literal[0] = 'X';  // ❌ WRONG! This will cause runtime error (segmentation fault)
```

#### Character Arrays (Modifiable)
```c
char str_array[] = "Hello World";   // Character array - stored in stack memory
str_array[0] = 'X';                 // ✅ CORRECT! This works fine
printf("Modified: %s\n", str_array); // Output: "Xello World"
```

#### Why This Difference Matters?

1. **String Literals** are stored in read-only memory segments
2. **Character Arrays** are stored in the stack (modifiable memory)
3. **Attempting to modify a string literal** causes undefined behavior (usually segmentation fault)

#### Complete Example Demonstrating the Difference
```c
#include <stdio.h>

int main() {
    // Method 1: String literal (read-only)
    char *literal = "Programming";
    printf("Original literal: %s\n", literal);
    
    // literal[0] = 'X';  // ❌ This will crash the program!
    
    // Method 2: Character array (modifiable)
    char array[] = "Programming";
    printf("Original array: %s\n", array);
    
    array[0] = 'X';  // ✅ This works perfectly
    printf("Modified array: %s\n", array);  // Output: "Xrogramming"
    
    // Method 3: Individual characters with null terminator
    char custom[] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', 'm', 'i', 'n', 'g', '\0'};
    custom[1] = 'X';  // ✅ This also works
    printf("Custom modified: %s\n", custom);  // Output: "PXogramming"
    
    return 0;
}
```

#### Best Practices
- **Use character arrays** when you need to modify the string
- **Use string literals** only for constant, read-only strings
- **Be careful** with `char *` declarations - they might point to read-only memory
- **Always initialize** character arrays properly to avoid undefined behavior

## How Strings are Stored

Strings are stored as arrays of characters in contiguous memory locations. Each character occupies 1 byte, and the string ends with a null character (`\0`).

**Memory Layout Example:**
```c
char name[] = "Gowtham";
```

**Memory Representation:**
```
Address: 1000  1001  1002  1003  1004  1005  1006  1007
Value:    G     o     w     t     h     a     m    \0
Index:    0     1     2     3     4     5     6     7
```

## The Null Character (`\0`)

- **Purpose**: Marks the end of a string
- **ASCII Value**: 0
- **Size**: 1 byte
- **Importance**: Without it, C functions can't determine where the string ends

**Example showing null character:**
```c
char str[] = "Hello";
printf("Length: %zu\n", strlen(str));  // Output: 5
printf("Size: %zu\n", sizeof(str));    // Output: 6 (includes \0)
```

## Input/Output Operations

### Output (Printing Strings)
```c
char name[] = "Gowtham";
printf("Name: %s\n", name);
puts(name);  // Automatically adds newline
```

### Input (Reading Strings)
```c
char name[50];
printf("Enter your name: ");
scanf("%s", name);  // Reads until whitespace
printf("Hello, %s!\n", name);
```

**Important Note**: When using `scanf()` with strings, we do **NOT** use the `&` symbol before the variable name. This is different from other data types.

**Why no `&` symbol for strings?**
- **Strings are arrays**: `name` is already a pointer to the first element
- **Arrays decay to pointers**: When we pass `name` to `scanf()`, it automatically becomes a pointer
- **Other data types need `&`**: `int`, `float`, `char` need `&` because we need to pass their memory address

**Comparison Examples:**
```c
int number;
char character;
char string[50];

// For other data types - NEED & symbol
scanf("%d", &number);      // &number gives address of int
scanf("%c", &character);   // &character gives address of char

// For strings - NO & symbol needed
scanf("%s", string);       // string is already a pointer (array name)
```

**Note**: `scanf()` with `%s` is unsafe for buffer overflow. Use `fgets()` for safer input.

## Character vs String

### Single Character
```c
char ch = 'A';        // Single character
printf("Character: %c\n", ch);  // Format specifier: %c
```

### String
```c
char str[] = "Hello";  // Array of characters
printf("String: %s\n", str);    // Format specifier: %s
```

**Key Differences:**
- **Character**: Single value, uses `%c`, size = 1 byte
- **String**: Array of characters, uses `%s`, size = number of characters + 1 (for `\0`)

## Taking User Input of Strings

### Using scanf() (Basic)
```c
char name[50];
printf("Enter name: ");
scanf("%s", name);
```

**Limitations:**
- Stops at whitespace
- No buffer overflow protection
- Can't read spaces

### Using fgets() (Recommended)
```c
char name[50];
printf("Enter name: ");
fgets(name, sizeof(name), stdin);

// Remove newline character if present
name[strcspn(name, "\n")] = '\0';
```

**Advantages:**
- Reads spaces
- Buffer overflow protection
- More control over input

### Using gets() (Deprecated - Avoid)
```c
// DON'T USE THIS - It's unsafe!
char name[50];
gets(name);  // Buffer overflow risk
```

## String Indexing

Strings use zero-based indexing, just like arrays.

```c
char str[] = "Gowtham";
printf("First character: %c\n", str[0]);    // G
printf("Third character: %c\n", str[2]);    // w
printf("Last character: %c\n", str[6]);     // m
```

**Accessing Individual Characters:**
```c
char str[] = "Hello";
for(int i = 0; str[i] != '\0'; i++) {
    printf("str[%d] = %c\n", i, str[i]);
}
```

## String Size and Length

### Size (Total Memory Allocated)
```c
char str[20] = "Hello";
printf("Size: %zu bytes\n", sizeof(str));  // 20 bytes
```

### Length (Actual Characters)
```c
char str[] = "Hello";
printf("Length: %zu characters\n", strlen(str));  // 5 characters
```

**Important Distinction:**
- `sizeof()` gives total allocated memory
- `strlen()` gives actual string length (excluding `\0`)

## Format Specifiers

### For Strings
```c
char str[] = "Hello World";
printf("String: %s\n", str);           // Basic string
printf("String: %20s\n", str);         // Right-aligned, 20 width
printf("String: %-20s\n", str);        // Left-aligned, 20 width
printf("String: %.5s\n", str);         // First 5 characters only
```

### For Characters
```c
char ch = 'A';
printf("Character: %c\n", ch);         // Single character
printf("ASCII value: %d\n", ch);       // ASCII value
```

## String Operations

### Concatenation
```c
char str1[50] = "Hello ";
char str2[] = "World";
strcat(str1, str2);  // Result: "Hello World"
```

### Copying
```c
char source[] = "Source String";
char destination[50];
strcpy(destination, source);  // Copy source to destination
```

### Comparison
```c
char str1[] = "Hello";
char str2[] = "Hello";
char str3[] = "World";

if(strcmp(str1, str2) == 0) {
    printf("Strings are equal\n");
}

if(strcmp(str1, str3) < 0) {
    printf("str1 comes before str3\n");
}
```

### Length
```c
char str[] = "Programming";
int len = strlen(str);  // len = 11
```

## String Functions (string.h library)

### Essential Functions

#### 1. strlen() - String Length
```c
#include <string.h>
char str[] = "Hello";
size_t length = strlen(str);  // Returns 5
```

#### 2. strcpy() - String Copy
```c
char dest[50];
char src[] = "Source";
strcpy(dest, src);  // Copies src to dest
```

#### 3. strncpy() - Bounded String Copy
```c
char dest[50];
char src[] = "Source String";
strncpy(dest, src, 5);  // Copies only first 5 characters
dest[5] = '\0';         // Manually add null terminator
```

#### 4. strcat() - String Concatenation
```c
char dest[50] = "Hello ";
char src[] = "World";
strcat(dest, src);  // Result: "Hello World"
```

#### 5. strncat() - Bounded String Concatenation
```c
char dest[50] = "Hello ";
char src[] = "World Programming";
strncat(dest, src, 5);  // Adds only "World"
```

#### 6. strcmp() - String Comparison
```c
char str1[] = "Hello";
char str2[] = "Hello";
char str3[] = "World";

int result1 = strcmp(str1, str2);  // Returns 0 (equal)
int result2 = strcmp(str1, str3);  // Returns negative (str1 < str3)
int result3 = strcmp(str3, str1);  // Returns positive (str3 > str1)
```

#### 7. strncmp() - Bounded String Comparison
```c
char str1[] = "Hello World";
char str2[] = "Hello Programming";
int result = strncmp(str1, str2, 5);  // Compares first 5 characters
```

### Advanced Functions

#### 8. strchr() - Find Character in String
```c
char str[] = "Hello World";
char *ptr = strchr(str, 'o');  // Points to first 'o'
if(ptr != NULL) {
    printf("Found 'o' at position: %ld\n", ptr - str);
}
```

#### 9. strstr() - Find Substring
```c
char str[] = "Hello World Programming";
char *ptr = strstr(str, "World");  // Points to "World Programming"
if(ptr != NULL) {
    printf("Found 'World' at position: %ld\n", ptr - str);
}
```

#### 10. strtok() - String Tokenization
```c
char str[] = "Hello,World,Programming";
char *token = strtok(str, ",");
while(token != NULL) {
    printf("Token: %s\n", token);
    token = strtok(NULL, ",");
}
```

## Complete Example Program

```c
#include <stdio.h>
#include <string.h>

int main() {
    // String declaration
    char name[50];
    char greeting[] = "Hello, ";
    
    // Taking user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    
    // Remove newline character
    name[strcspn(name, "\n")] = '\0';
    
    // String operations
    strcat(greeting, name);
    strcat(greeting, "!");
    
    // Display results
    printf("Greeting: %s\n", greeting);
    printf("Name length: %zu characters\n", strlen(name));
    printf("Total greeting length: %zu characters\n", strlen(greeting));
    
    // Character by character access
    printf("Your name spelled out: ");
    for(int i = 0; name[i] != '\0'; i++) {
        printf("%c ", name[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Common Pitfalls and Best Practices

### 1. Always Include Null Terminator
```c
// WRONG - Missing null terminator
char str[] = {'H', 'e', 'l', 'l', 'o'};

// CORRECT - Include null terminator
char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

### 2. Check Buffer Sizes
```c
char dest[10];
char src[] = "This is a very long string";
// strcpy(dest, src);  // Buffer overflow!

strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';  // Ensure null termination
```

### 3. Use Safe Input Functions
```c
// Instead of scanf("%s", str)
fgets(str, sizeof(str), stdin);
```

### 4. Initialize Arrays
```c
char str[100] = {0};  // Initialize all elements to 0 (null)
```

### 5. Remember: No & Symbol for Strings in scanf()
```c
// CORRECT - No & symbol for strings
char name[50];
scanf("%s", name);

// WRONG - Don't use & with strings
char name[50];
scanf("%s", &name);  // This will cause compilation error or undefined behavior

// CORRECT - Use & for other data types
int age;
scanf("%d", &age);
```

### 6. Never Modify String Literals
```c
// WRONG - This will crash your program!
char *literal = "Hello";
literal[0] = 'X';  // ❌ Segmentation fault!

// CORRECT - Use character arrays for modifiable strings
char array[] = "Hello";
array[0] = 'X';    // ✅ This works fine
```

## Summary

- **Strings** are arrays of characters terminated by `\0`
- **Null character** (`\0`) marks the end of a string
- **Indexing** starts at 0 and goes up to length-1
- **Size** includes the null terminator, **length** doesn't
- **Format specifier** `%s` for strings, `%c` for characters
- **String functions** are in `<string.h>` library
- **Always** ensure proper null termination
- **Use safe functions** like `fgets()` instead of `gets()`
- **Check buffer sizes** to prevent overflow
- **No `&` symbol** needed when using `scanf()` with strings (unlike other data types)
- **String literals are read-only** - never modify them (use character arrays instead)

Understanding strings is fundamental to C programming, as they're used extensively in text processing, user input, and data manipulation.


---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](11_array_examples.md) | [🏠 Home](README.md) | [➡️ Next](13_structures.md)

</div>