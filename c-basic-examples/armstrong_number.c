/*
 * Topic: Armstrong Number Check
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to check if a number is an Armstrong number
 *
 * Prerequisites: Loops, arithmetic
 *
 * Technical Details:
 * - An Armstrong number is equal to sum of cubes of its digits (for 3-digit numbers)
 *
 * Dependencies:
 * - Standard C library (stdio.h), math library (math.h)
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n, sum = 0, temp, digits = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp != 0) {
        int r = temp % 10;
        sum += pow(r, digits);
        temp /= 10;
    }

    if (sum == n)
        printf("%d is an Armstrong number\n", n);
    else
        printf("%d is not an Armstrong number\n", n);

    return 0;
}
