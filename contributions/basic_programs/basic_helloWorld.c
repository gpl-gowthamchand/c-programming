/*
 * Program: Hello World Variations
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * Description: Different ways to print "Hello World" in C
 */

#include <stdio.h>

int main() {
    // Method 1: Simple printf
    printf("Hello, World!\n");
    
    // Method 2: Using puts
    puts("Hello, World!");
    
    // Method 3: Using putchar for each character
    char message[] = "Hello, World!\n";
    for (int i = 0; message[i] != '\0'; i++) {
        putchar(message[i]);
    }
    
    // Method 4: Formatted output
    char name[] = "World";
    printf("Hello, %s!\n", name);
    
    // Method 5: Multiple lines
    printf("Hello,\n");
    printf("World!\n");
    
    return 0;
}
