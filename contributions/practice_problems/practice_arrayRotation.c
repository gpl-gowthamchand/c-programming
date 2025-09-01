/*
 * Problem: Array Rotation
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Problem Statement:
 * Given an array and a number k, rotate the array to the right by k steps.
 * 
 * Input: 
 * - Array of integers
 * - Number of rotation steps (k)
 * 
 * Output: Rotated array
 * 
 * Example:
 * Input: [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * 
 * Input: [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * 
 * Approach: 
 * 1. Reverse the entire array
 * 2. Reverse the first k elements
 * 3. Reverse the remaining elements
 * 
 * Time Complexity: O(n) where n is the length of the array
 * Space Complexity: O(1) - using constant extra space
 * 
 * Test Cases:
 * - [1,2,3,4,5,6,7], k=3 -> [5,6,7,1,2,3,4]
 * - [-1,-100,3,99], k=2 -> [3,99,-1,-100]
 * - [1,2], k=1 -> [2,1]
 * - [1], k=1 -> [1]
 */

#include <stdio.h>

// Function to reverse array elements from start to end
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate array to the right by k steps
void rotateArray(int arr[], int n, int k) {
    // Handle case where k is greater than array length
    k = k % n;
    
    // If k is 0, no rotation needed
    if (k == 0) {
        return;
    }
    
    // Step 1: Reverse the entire array
    reverse(arr, 0, n - 1);
    
    // Step 2: Reverse the first k elements
    reverse(arr, 0, k - 1);
    
    // Step 3: Reverse the remaining elements
    reverse(arr, k, n - 1);
}

// Function to print array
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]");
}

int main() {
    printf("=== Array Rotation Problem ===\n");
    
    // Test Case 1
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 3;
    
    printf("Original array: ");
    printArray(arr1, n1);
    printf("\nRotating right by %d steps...\n", k1);
    
    rotateArray(arr1, n1, k1);
    
    printf("Rotated array: ");
    printArray(arr1, n1);
    printf("\n\n");
    
    // Test Case 2
    int arr2[] = {-1, -100, 3, 99};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 2;
    
    printf("Original array: ");
    printArray(arr2, n2);
    printf("\nRotating right by %d steps...\n", k2);
    
    rotateArray(arr2, n2, k2);
    
    printf("Rotated array: ");
    printArray(arr2, n2);
    printf("\n\n");
    
    // Interactive test
    printf("=== Interactive Test ===\n");
    printf("Enter array size: ");
    int n;
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter number of rotations: ");
    int k;
    scanf("%d", &k);
    
    printf("Original array: ");
    printArray(arr, n);
    printf("\n");
    
    rotateArray(arr, n, k);
    
    printf("Rotated array: ");
    printArray(arr, n);
    printf("\n");
    
    return 0;
}
