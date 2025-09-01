/*
 * Program: Factorial Calculator
 * Author: Pradeep-CodeZ
 * Date: 17 Aug 2025
 * Description: Calculates the factorial of a given positive integer.
 * 
 * Features:
 * - Checks for negative input and handles it gracefully
 * - Calculates factorial using a loop
 * 
 * Usage: Compile and run the program
 * Example: gcc basic_Factorial.c -o basic_Factorial && ./basic_Factorial
 */

#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else {
        for (i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return 0;

}