/*
 * Topic: Reverse a String
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to reverse a given string
 *
 * Prerequisites: Arrays, loops, string handling
 *
 * Technical Details:
 * - Uses character array
 * - Swaps characters from both ends
 *
 * Performance Characteristics:
 * - Time Complexity: O(n)
 * - Space Complexity: O(1)
 *
 * Dependencies:
 * - Standard C library (stdio.h, string.h)
 *
 * Testing:
 * - Input: "hello" → Output: "olleh"
 * - Input: "C programming" → Output: "gnimmargorp C"
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);
    return 0;
}
