/*
 * Topic: Prime Number Check
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to check whether a number is prime or not
 *
 * Prerequisites: Loops, conditional statements
 *
 * Technical Details:
 * - Checks divisibility from 2 to sqrt(n)
 *
 * Performance Characteristics:
 * - Time Complexity: O(√n)
 * - Space Complexity: O(1)
 *
 * Dependencies:
 * - Standard C library (stdio.h), math library (math.h)
 *
 * Testing:
 * - Input: 7 → Output: Prime
 * - Input: 10 → Output: Not Prime
 * - Edge case: 1 → Not Prime
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d is not a prime number\n", n);
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("%d is a Prime number\n", n);
    else
        printf("%d is Not a Prime number\n", n);

    return 0;
}
