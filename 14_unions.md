# Unions in C Programming

## 🧭 **Navigation**
| ⬅️ Previous | 🏠 Home | ➡️ Next |
|:------------|:--------|:--------|
| [13 Structures](13_structures.md) | [README](README.md) | [15 Enums](15_enums.md) |

---

## What are Unions?

A union is a special data type in C that allows you to store different data types in the same memory location. Unlike structures, unions can only hold one member value at a time, and all members share the same memory space.

## Key Characteristics

- **Memory Sharing**: All members share the same memory location
- **Single Value**: Only one member can be active at any given time
- **Memory Efficiency**: Uses only the size of the largest member
- **Type Flexibility**: Can represent different data types in the same variable

## Syntax

```c
union union_name {
    data_type member1;
    data_type member2;
    data_type member3;
    // ... more members
};
```

## Declaration and Usage

```c
// Declaring a union
union Data {
    int i;
    float f;
    char str[20];
};

// Creating union variables
union Data data;
union Data *ptr;

// Accessing members
data.i = 10;        // Set integer value
data.f = 220.5;     // Overwrites the integer value
strcpy(data.str, "C Programming"); // Overwrites the float value
```

## Memory Layout

```c
union Example {
    int x;      // 4 bytes
    char y;     // 1 byte
    double z;   // 8 bytes
}; // Total size: 8 bytes (size of largest member)
```

## Practical Examples

### Example 1: Basic Union Usage

```c
#include <stdio.h>
#include <string.h>

union Value {
    int integer;
    float floating;
    char string[50];
};

int main() {
    union Value val;
    
    val.integer = 42;
    printf("Integer: %d\n", val.integer);
    
    val.floating = 3.14;
    printf("Float: %.2f\n", val.floating);
    
    strcpy(val.string, "Hello Union!");
    printf("String: %s\n", val.string);
    
    return 0;
}
```

### Example 2: Union with Structures

```c
#include <stdio.h>

struct Point2D {
    int x, y;
};

struct Point3D {
    int x, y, z;
};

union Shape {
    struct Point2D point2d;
    struct Point3D point3d;
    int radius;
};

int main() {
    union Shape shape;
    
    // Use as 2D point
    shape.point2d.x = 10;
    shape.point2d.y = 20;
    printf("2D Point: (%d, %d)\n", shape.point2d.x, shape.point2d.y);
    
    // Use as radius
    shape.radius = 5;
    printf("Radius: %d\n", shape.radius);
    
    return 0;
}
```

### Example 3: Type Tagged Union

```c
#include <stdio.h>
#include <string.h>

enum DataType {
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE
};

struct TaggedUnion {
    enum DataType type;
    union {
        int i;
        float f;
        char str[100];
    } data;
};

void printValue(struct TaggedUnion *tu) {
    switch(tu->type) {
        case INT_TYPE:
            printf("Integer: %d\n", tu->data.i);
            break;
        case FLOAT_TYPE:
            printf("Float: %.2f\n", tu->data.f);
            break;
        case STRING_TYPE:
            printf("String: %s\n", tu->data.str);
            break;
    }
}

int main() {
    struct TaggedUnion tu;
    
    tu.type = INT_TYPE;
    tu.data.i = 100;
    printValue(&tu);
    
    tu.type = FLOAT_TYPE;
    tu.data.f = 3.14159;
    printValue(&tu);
    
    tu.type = STRING_TYPE;
    strcpy(tu.data.str, "Union Example");
    printValue(&tu);
    
    return 0;
}
```

## Common Use Cases

1. **Memory Optimization**: When you need to store different types but only use one at a time
2. **Type Flexibility**: Creating variables that can hold different data types
3. **Hardware Interface**: Working with hardware registers that can be interpreted differently
4. **Protocol Implementation**: Parsing different message formats
5. **Variant Records**: Similar to discriminated unions in other languages

## Important Considerations

### Memory Overwriting
```c
union Test {
    int a;
    char b;
};

union Test t;
t.a = 0x12345678;
printf("a = 0x%x\n", t.a);  // Output: 0x12345678
printf("b = 0x%x\n", t.b);  // Output: 0x78 (lowest byte)
```

### Size and Alignment
```c
union SizeTest {
    char c;      // 1 byte
    int i;       // 4 bytes
    double d;    // 8 bytes
};

printf("Size: %zu bytes\n", sizeof(union SizeTest)); // Output: 8 bytes
```

## Union vs Structure

| Feature | Union | Structure |
|---------|-------|-----------|
| Memory | Shared among members | Separate for each member |
| Size | Size of largest member | Sum of all members |
| Usage | One member at a time | All members simultaneously |
| Memory Efficiency | High | Lower |

## Best Practices

1. **Always track which member is currently valid**
2. **Use type tags when possible**
3. **Be careful with memory alignment issues**
4. **Document the intended usage clearly**
5. **Consider using structures when you need multiple values simultaneously**

## Common Pitfalls

1. **Forgetting which member was last set**
2. **Accessing uninitialized members**
3. **Ignoring endianness in cross-platform code**
4. **Memory alignment issues on some architectures**

## Advanced Usage: Anonymous Unions

```c
struct Advanced {
    int type;
    union {
        int i;
        float f;
        char *s;
    }; // Anonymous union
};

int main() {
    struct Advanced adv;
    adv.type = 1;
    adv.i = 42; // Direct access without union name
    
    return 0;
}
```

## Summary

Unions are powerful tools in C for:
- Memory-efficient storage of different data types
- Creating flexible data structures
- Hardware interface programming
- Protocol implementation

Remember that unions share memory, so only one member should be active at a time. Always use proper type tracking to avoid undefined behavior.
