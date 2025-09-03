/*
 * Topic: Sum of Numbers (Loop)
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to calculate the sum of the first n natural numbers using a loop
 *
 * Prerequisites: Basics of C, variables, loops, input/output
 *
 * Technical Details:
 * - Uses for loop
 * - Iterative summation
 *
 * Performance Characteristics:
 * - Time Complexity: O(n)
 * - Space Complexity: O(1)
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 *
 * Testing:
 * - Input small n (e.g., 5 → sum=15)
 * - Input larger n (e.g., 100 → sum=5050)
 * - Edge case: n=0 → sum=0
 */

#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum of first %d natural numbers = %d\n", n, sum);
    return 0;
}
