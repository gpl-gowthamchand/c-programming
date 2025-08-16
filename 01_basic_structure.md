# Basic Structure of a C Program

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](00_intro_to_c_programming.md) | [🏠 Home](README.md) | [➡️ Next](02_tokens.md)

</div>

---

## 🚀 Your First C Program

Let's start with the classic "Hello, World!" program. This is the traditional first program that every programmer writes when learning a new language.

## 📝 The Code

```c
#include <stdio.h>      // Preprocessor directive: includes standard input/output library

int main(){             // Main function - program entry point
    printf("Hello, World!"); // Print "Hello, World!" to the console
    return 0;           // Return 0 to indicate successful completion
}
```

## 🔍 Understanding Each Part

### **1. `#include <stdio.h>`**
- **What it does**: Includes the standard input/output library
- **Why needed**: Gives us access to functions like `printf()`
- **`stdio.h`**: Stands for "Standard Input Output Header"

### **2. `int main()`**
- **What it is**: The main function - where program execution begins
- **`int`**: Return type (integer)
- **`main`**: Function name (must be exactly "main")
- **`()`**: Empty parentheses mean no parameters

### **3. `printf("Hello, World!");`**
- **What it does**: Displays text on the screen
- **`printf`**: Function to print formatted output
- **`"Hello, World!"`**: The text to display (string literal)
- **`;`**: Semicolon marks the end of the statement

### **4. `return 0;`**
- **What it does**: Ends the program and returns a value to the operating system
- **`0`**: Indicates successful completion
- **Why 0**: Convention - 0 means success, non-zero means error

## 🏗️ Program Structure

Every C program follows this basic structure:

```c
#include <header_files>     // Include necessary libraries

int main() {                // Main function (entry point)
    // Your code here       // Program statements
    return 0;               // End program
}
```

## 🚀 How to Run This Program

### **Step 1: Save the Code**
Save the code in a file named `basic_structure.c`

### **Step 2: Compile**
```bash
gcc basic_structure.c -o basic_structure
```

### **Step 3: Run**
```bash
./basic_structure
```

### **Expected Output:**
```
Hello, World!
```

## ⚠️ Important Notes

### **Semicolons**
- **Always** end statements with semicolons (`;`)
- Missing semicolons cause compilation errors

### **Case Sensitivity**
- C is case-sensitive: `printf` ≠ `Printf` ≠ `PRINTF`
- Use exact spelling as shown

### **Curly Braces**
- Every opening brace `{` must have a closing brace `}`
- Braces define the scope of functions and blocks

### **Comments**
- `//` for single-line comments
- `/* */` for multi-line comments
- Comments help explain your code

## 🎯 What You've Learned

1. **Basic C program structure**
2. **How to include libraries**
3. **Main function syntax**
4. **Using printf() function**
5. **Proper program termination**

## 🔄 Practice Exercise

Try modifying the program to print your name instead of "Hello, World!":

```c
#include <stdio.h>

int main() {
    printf("Hello, [Your Name]!\n");  // Replace [Your Name] with your actual name
    return 0;
}
```

## 🚀 Next Steps

Now that you understand the basic structure, you're ready to learn about:
- **Tokens** - The building blocks of C programs
- **Variables** - Storing and manipulating data
- **Data types** - Different kinds of information

---

<div align="right">

**🧭 Navigation**  
[⬅️ Previous](00_intro_to_c_programming.md) | [🏠 Home](README.md) | [➡️ Next](02_tokens.md)

</div>
