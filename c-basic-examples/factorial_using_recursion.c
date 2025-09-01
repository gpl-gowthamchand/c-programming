/*
 * Topic: Factorial Calculation
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to calculate factorial of a number using recursion
 *
 * Prerequisites: Recursion, functions, basic math
 *
 * Technical Details:
 * - Recursive function factorial(n)
 * - Handles n=0 as base case
 *
 * Performance Characteristics:
 * - Time Complexity: O(n)
 * - Space Complexity: O(n) due to recursion stack
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 *
 * Testing:
 * - Input: 5 → Output: 120
 * - Input: 0 → Output: 1
 * - Input: negative number → undefined (not handled)
 */

#include <stdio.h>

long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial not defined for negative numbers\n");
    } else {
        printf("Factorial of %d = %ld\n", n, factorial(n));
    }
    return 0;
}
