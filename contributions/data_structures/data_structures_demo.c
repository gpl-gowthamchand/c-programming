/*
 * Topic: Structures, Unions, and Enums Demo
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program demonstrating structures, unions, and enums in C
 *
 * Prerequisites: Structures, unions, enums
 *
 * Technical Details:
 * - Structure to hold student details
 * - Union to store different data types
 * - Enum for grade levels
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 *
 * Testing:
 * - Create student and display details
 * - Show memory sharing in union
 * - Print enum values
 */

#include <stdio.h>
#include <string.h>

// Enum for grades
enum Grade { A, B, C, D, F };

// Structure for student
struct Student {
    int roll;
    char name[50];
    enum Grade grade;
};

// Union for demonstrating memory sharing
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    struct Student s1;
    s1.roll = 1;
    strcpy(s1.name, "John Doe");
    s1.grade = B;

    printf("Student Details:\nRoll: %d\nName: %s\nGrade: %d\n\n", s1.roll, s1.name, s1.grade);

    union Data d;
    d.i = 10;
    printf("Union int: %d\n", d.i);

    d.f = 3.14;
    printf("Union float: %.2f (int gets overwritten)\n", d.f);

    strcpy(d.str, "Hello");
    printf("Union string: %s (previous values lost)\n", d.str);

    return 0;
}
