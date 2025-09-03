/*
 * Topic: Palindrome Check
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to check if a string and a number are palindromes
 *
 * Prerequisites: Strings, loops, arithmetic
 *
 * Technical Details:
 * - String reversal for string palindrome
 * - Reverse digits for number palindrome
 *
 * Dependencies:
 * - Standard C library (stdio.h, string.h)
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str), flag = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    printf("String %s is %s palindrome\n", str, flag ? "a" : "not a");

    int n, rev = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;

    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    if (rev == n)
        printf("Number %d is a palindrome\n", n);
    else
        printf("Number %d is not a palindrome\n", n);

    return 0;
}
