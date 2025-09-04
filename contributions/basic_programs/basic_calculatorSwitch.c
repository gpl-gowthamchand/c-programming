/*
 * Topic: Simple Calculator (Switch Case)
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Calculator program using switch-case for +, -, *, /
 *
 * Prerequisites: Switch-case, operators
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 */

#include <stdio.h>

int main() {
    char op;
    double a, b;
    printf("Enter expression (a op b): ");
    scanf("%lf %c %lf", &a, &op, &b);

    switch (op) {
        case '+': printf("Result: %.2lf\n", a + b); break;
        case '-': printf("Result: %.2lf\n", a - b); break;
        case '*': printf("Result: %.2lf\n", a * b); break;
        case '/': 
            if (b != 0) printf("Result: %.2lf\n", a / b);
            else printf("Error: Division by zero\n");
            break;
        default: printf("Invalid operator\n");
    }

    return 0;
}
