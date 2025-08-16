# Structures in C Programming

## 🧭 **Navigation**
| ⬅️ Previous | 🏠 Home | ➡️ Next |
|:------------|:--------|:--------|
| [12 Strings](12_strings.md) | [README](README.md) | [14 Unions](14_unions.md) |

---

## Introduction
Structures in C are user-defined data types that allow you to group different types of data under a single name. They are essential for creating complex data structures and organizing related data.

## Basic Syntax

### Structure Declaration
```c
struct structure_name {
    data_type member1;
    data_type member2;
    // ... more members
};
```

### Structure Definition
```c
struct Person {
    char name[50];
    int age;
    float height;
    char city[30];
};
```

## Creating Structure Variables

### Method 1: Separate Declaration and Definition
```c
struct Person {
    char name[50];
    int age;
    float height;
};

struct Person person1, person2;
```

### Method 2: Declaration with Definition
```c
struct Person {
    char name[50];
    int age;
    float height;
} person1, person2;
```

### Method 3: Using typedef
```c
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

Person person1, person2;  // No need for 'struct' keyword
```

## Accessing Structure Members

### Dot Operator (.)
```c
struct Person person1;
person1.age = 25;
strcpy(person1.name, "John");
person1.height = 175.5;
```

### Arrow Operator (->) for Pointers
```c
struct Person *ptr = &person1;
ptr->age = 25;           // Same as (*ptr).age = 25
strcpy(ptr->name, "John");
ptr->height = 175.5;
```

## Structure Initialization

### Method 1: Member-wise Initialization
```c
struct Person person1 = {"John", 25, 175.5};
```

### Method 2: Designated Initialization (C99)
```c
struct Person person1 = {
    .name = "John",
    .age = 25,
    .height = 175.5
};
```

### Method 3: Zero Initialization
```c
struct Person person1 = {0};  // All members set to 0/NULL
```

## Nested Structures

### Structure within Structure
```c
struct Address {
    char street[100];
    char city[50];
    char state[30];
    int zipcode;
};

struct Person {
    char name[50];
    int age;
    struct Address address;
};

// Accessing nested members
struct Person person1;
strcpy(person1.address.city, "New York");
person1.address.zipcode = 10001;
```

### Self-Referential Structures
```c
struct Node {
    int data;
    struct Node *next;
};
```

## Arrays of Structures

```c
struct Person people[100];

// Accessing array elements
people[0].age = 25;
strcpy(people[1].name, "Alice");
```

## Structures and Functions

### Passing Structure by Value
```c
void printPerson(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.2f\n", p.height);
}

// Function call
printPerson(person1);
```

### Passing Structure by Reference
```c
void updateAge(struct Person *p, int newAge) {
    p->age = newAge;
}

// Function call
updateAge(&person1, 26);
```

### Returning Structure
```c
struct Person createPerson(char name[], int age, float height) {
    struct Person p;
    strcpy(p.name, name);
    p.age = age;
    p.height = height;
    return p;
}

// Function call
struct Person person2 = createPerson("Alice", 30, 165.0);
```

## Structure Padding and Memory

### Understanding Padding
```c
struct Example1 {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
}; // Total: 12 bytes due to padding

struct Example2 {
    char a;     // 1 byte
    char c;     // 1 byte
    int b;      // 4 bytes
}; // Total: 8 bytes (more efficient)
```

### Using #pragma pack
```c
#pragma pack(1)
struct Packed {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
}; // Total: 6 bytes (no padding)
#pragma pack()
```

## Practical Examples

### Student Management System
```c
struct Student {
    int roll_no;
    char name[100];
    float marks[5];
    float average;
};

void calculateAverage(struct Student *s) {
    float sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += s->marks[i];
    }
    s->average = sum / 5.0;
}

void displayStudent(struct Student s) {
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks: ");
    for(int i = 0; i < 5; i++) {
        printf("%.2f ", s.marks[i]);
    }
    printf("\nAverage: %.2f\n", s.average);
}
```

### Complex Data Structure
```c
struct Date {
    int day;
    int month;
    int year;
};

struct Book {
    char title[100];
    char author[100];
    char isbn[20];
    float price;
    struct Date publish_date;
    int pages;
    char category[50];
};

void addBook(struct Book *library, int *count, struct Book newBook) {
    library[*count] = newBook;
    (*count)++;
}

void searchByAuthor(struct Book *library, int count, char author[]) {
    for(int i = 0; i < count; i++) {
        if(strcmp(library[i].author, author) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("ISBN: %s\n", library[i].isbn);
            printf("Price: $%.2f\n\n", library[i].price);
        }
    }
}
```

## Best Practices

1. **Use meaningful names** for structures and members
2. **Group related data** together in a single structure
3. **Consider memory layout** when designing structures
4. **Use typedef** for cleaner code when appropriate
5. **Initialize structures** properly to avoid undefined behavior
6. **Pass large structures by reference** to avoid copying overhead
7. **Document structure members** with comments for clarity

## Common Pitfalls

1. **Forgetting to include necessary headers** (e.g., `<string.h>` for `strcpy`)
2. **Accessing uninitialized structure members**
3. **Comparing structures directly** (use member-wise comparison)
4. **Ignoring structure padding** in memory-critical applications
5. **Not checking pointer validity** before using arrow operator

## Summary

Structures are fundamental building blocks in C programming that enable:
- Organization of related data
- Creation of complex data types
- Building sophisticated data structures
- Better code organization and readability

Understanding structures is crucial for advanced C programming, including linked lists, trees, graphs, and other data structures.
