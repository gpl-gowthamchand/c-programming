/*
 * Algorithm: Binary Search
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * Description: Implementation of binary search algorithm for finding elements in sorted arrays
 * 
 * Time Complexity: O(log n) - logarithmic time complexity
 * Space Complexity: O(1) - iterative version, O(log n) - recursive version
 * 
 * Features:
 * - Works only on sorted arrays
 * - Much faster than linear search for large datasets
 * - Divide and conquer approach
 * 
 * Usage: gcc algorithms_binarySearch.c -o binarySearch && ./binarySearch
 */

#include <stdio.h>

// Iterative implementation
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // Target not found
    return -1;
}

// Recursive implementation
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        // If element is present at middle
        if (arr[mid] == target) {
            return mid;
        }
        
        // If element is smaller than mid, search left subarray
        if (arr[mid] > target) {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
        
        // Else search right subarray
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    
    // Element not present
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Iterative search
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element %d not found (iterative)\n", target);
    } else {
        printf("Element %d found at index %d (iterative)\n", target, result);
    }
    
    // Recursive search
    result = binarySearchRecursive(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element %d not found (recursive)\n", target);
    } else {
        printf("Element %d found at index %d (recursive)\n", target, result);
    }
    
    return 0;
}
