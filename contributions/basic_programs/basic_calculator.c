/*
 * Program: Basic Calculator
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * Description: Simple calculator for basic arithmetic operations
 */

#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;
    
    printf("=== Basic Calculator ===\n");
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is not allowed!\n");
            }
            break;
            
        default:
            printf("Error: Invalid operator!\n");
    }
    
    return 0;
}
