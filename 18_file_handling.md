# File Handling in C Programming

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](17_dynamic_memory_allocation.md) | [🏠 Home](README.md) | [➡️ Next](19_storage_classes.md)

</div>

---


## Overview
File handling in C allows you to create, read, write, and manipulate files on your computer's storage. C provides a set of functions in the `<stdio.h>` header file for file operations.

## File Types
- **Text Files**: Human-readable files containing text
- **Binary Files**: Files containing data in binary format (images, executables, etc.)

## File Operations
1. **Opening a file** - `fopen()`
2. **Reading from a file** - `fgetc()`, `fgets()`, `fscanf()`, `fread()`
3. **Writing to a file** - `fputc()`, `fputs()`, `fprintf()`, `fwrite()`
4. **Closing a file** - `fclose()`
5. **File positioning** - `fseek()`, `rewind()`, `ftell()`

## File Modes
When opening a file with `fopen()`, you specify the mode:

| Mode | Description |
|------|-------------|
| `"r"` | Read mode (file must exist) |
| `"w"` | Write mode (creates new file, truncates existing) |
| `"a"` | Append mode (creates new file, adds to existing) |
| `"r+"` | Read and write mode |
| `"w+"` | Read and write mode (truncates existing) |
| `"a+"` | Read and append mode |
| `"rb"`, `"wb"`, `"ab"` | Binary file modes |

## Basic File Operations

### 1. Opening a File
```c
FILE *filePointer;
filePointer = fopen("filename.txt", "r");
if (filePointer == NULL) {
    printf("Error opening file!\n");
    return 1;
}
```

### 2. Closing a File
```c
fclose(filePointer);
```

### 3. Reading from a File

#### Character by Character
```c
char ch;
while ((ch = fgetc(filePointer)) != EOF) {
    printf("%c", ch);
}
```

#### Line by Line
```c
char buffer[100];
while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
    printf("%s", buffer);
}
```

#### Formatted Reading
```c
int number;
char name[50];
fscanf(filePointer, "%d %s", &number, name);
```

### 4. Writing to a File

#### Character by Character
```c
fputc('A', filePointer);
```

#### String
```c
fputs("Hello World", filePointer);
```

#### Formatted Writing
```c
fprintf(filePointer, "Number: %d, Name: %s\n", 42, "John");
```

## Complete Example: Text File Operations

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;
    
    // Writing to a file
    file = fopen("test.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    
    fprintf(file, "Hello, this is a test file!\n");
    fprintf(file, "Line 2: Learning file handling in C\n");
    fclose(file);
    
    // Reading from the file
    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);
    
    return 0;
}
```

## Binary File Operations

### Writing Binary Data
```c
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    FILE *file;
    struct Student student = {101, "Alice", 3.8};
    
    file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fwrite(&student, sizeof(struct Student), 1, file);
    fclose(file);
    
    return 0;
}
```

### Reading Binary Data
```c
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    FILE *file;
    struct Student student;
    
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fread(&student, sizeof(struct Student), 1, file);
    printf("ID: %d, Name: %s, GPA: %.2f\n", 
           student.id, student.name, student.gpa);
    
    fclose(file);
    return 0;
}
```

## File Positioning Functions

### 1. `fseek()` - Move to a specific position
```c
// Move to beginning of file
fseek(filePointer, 0, SEEK_SET);

// Move to end of file
fseek(filePointer, 0, SEEK_END);

// Move relative to current position
fseek(filePointer, 10, SEEK_CUR);  // Move 10 bytes forward
```

### 2. `rewind()` - Move to beginning of file
```c
rewind(filePointer);  // Same as fseek(filePointer, 0, SEEK_SET)
```

### 3. `ftell()` - Get current position
```c
long position = ftell(filePointer);
printf("Current position: %ld\n", position);
```

## Error Handling
Always check for errors when working with files:

```c
FILE *file = fopen("filename.txt", "r");
if (file == NULL) {
    perror("Error opening file");  // Prints system error message
    return 1;
}
```

## File Status Functions

### 1. `feof()` - Check if end of file reached
```c
while (!feof(filePointer)) {
    // Read file
}
```

### 2. `ferror()` - Check for file errors
```c
if (ferror(filePointer)) {
    printf("An error occurred while reading the file\n");
    clearerr(filePointer);  // Clear error flag
}
```

## Practical Example: Copy File

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    char ch;
    
    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }
    
    source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Cannot open source file %s\n", argv[1]);
        return 1;
    }
    
    destination = fopen(argv[2], "w");
    if (destination == NULL) {
        printf("Cannot create destination file %s\n", argv[2]);
        fclose(source);
        return 1;
    }
    
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    
    fclose(source);
    fclose(destination);
    
    printf("File copied successfully!\n");
    return 0;
}
```

## Best Practices

1. **Always check** if file operations succeed
2. **Close files** when you're done with them
3. **Use appropriate modes** for your operations
4. **Handle errors gracefully** with proper error messages
5. **Use binary mode** for non-text files
6. **Check file existence** before operations
7. **Use buffered I/O** for better performance

## Common Pitfalls

1. **Forgetting to close files** - can cause resource leaks
2. **Not checking return values** - can lead to silent failures
3. **Using wrong file modes** - can corrupt files
4. **Not handling EOF properly** - can cause infinite loops
5. **Buffer overflow** - when reading into fixed-size arrays

## Summary
File handling in C provides powerful tools for working with files. Understanding the different modes, functions, and proper error handling is essential for creating robust file-based applications. Always remember to open, use, and close files properly to avoid resource leaks and ensure data integrity.


---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](17_dynamic_memory_allocation.md) | [🏠 Home](README.md) | [➡️ Next](19_storage_classes.md)

</div>