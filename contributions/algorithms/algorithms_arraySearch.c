/*
 * Topic: Search in an Array
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to search for an element in an array using linear search
 *
 * Prerequisites: Arrays, loops, conditionals
 *
 * Technical Details:
 * - Linear search implementation
 *
 * Performance Characteristics:
 * - Time Complexity: O(n)
 * - Space Complexity: O(1)
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 *
 * Testing:
 * - Input: [10, 20, 30, 40], search=30 → Found
 * - Input: [10, 20, 30, 40], search=50 → Not Found
 */

#include <stdio.h>

int main() {
    int n, key, found = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element %d not found in array\n", key);

    return 0;
}
