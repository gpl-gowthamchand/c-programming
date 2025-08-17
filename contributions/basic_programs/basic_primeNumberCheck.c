/*
 * Program: Prime Number Checker
 * Author: Pradeep-CodeZ
 * Date: 17 Aug 2025
 * Description: Checks whether a given integer is a prime number.
 * 
 * Features:
 * - Handles numbers less than 2
 * - Efficiently checks for primality using a loop
 * 
 * Usage: Compile and run the program
 * Example: gcc basic_PrimeChecker.c -o basic_PrimeChecker && ./basic_PrimeChecker
 */

#include <stdio.h>

int main() {
    int n, i, isPrime = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("%d is not a prime number.\n", n);
        return 0;
    }

    for (i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;

}