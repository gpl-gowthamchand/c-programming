/*
 * Algorithm: Bubble Sort
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * Description: Implementation of bubble sort algorithm for sorting arrays
 * 
 * Time Complexity: O(n²) - worst and average case
 * Space Complexity: O(1) - constant extra space
 * 
 * Features:
 * - In-place sorting algorithm
 * - Stable sorting (maintains relative order of equal elements)
 * - Simple to understand and implement
 * 
 * Usage: gcc algorithms_bubbleSort.c -o bubbleSort && ./bubbleSort
 */

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n-1; i++) {
        swapped = 0; // Flag to check if any swap occurred
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        
        // If no swapping occurred, array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
