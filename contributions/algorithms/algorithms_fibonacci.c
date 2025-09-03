/*
 * Topic: Fibonacci Series
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to generate Fibonacci numbers using both loop and recursion
 *
 * Prerequisites: Loops, recursion, functions
 *
 * Technical Details:
 * - Iterative approach (loop)
 * - Recursive approach (function)
 *
 * Performance Characteristics:
 * - Iterative: O(n) time, O(1) space
 * - Recursive: O(2^n) time, O(n) space (not efficient)
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 */

#include <stdio.h>

int fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci (Iterative): ");
    int a = 0, b = 1, c;
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }

    printf("\nFibonacci (Recursive): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibRecursive(i));
    }

    printf("\n");
    return 0;
}
