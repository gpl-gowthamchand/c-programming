/*
 * Topic: Matrix Multiplication
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to multiply two matrices
 *
 * Prerequisites: 2D arrays, nested loops
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 */

#include <stdio.h>

int main() {
    int a[10][10], b[10][10], res[10][10], r1, c1, r2, c2;

    printf("Enter rows and cols of matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols of matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    printf("Enter elements of A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    // Multiply
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Result Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
