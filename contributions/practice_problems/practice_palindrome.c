/*
 * Problem: Palindrome Checker
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Problem Statement:
 * Write a program to check if a given string is a palindrome.
 * A palindrome is a word, phrase, number, or other sequence of characters
 * that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).
 * 
 * Input: A string (can contain letters, numbers, spaces, punctuation)
 * Output: "Palindrome" or "Not a palindrome"
 * 
 * Example:
 * Input: "A man a plan a canal Panama"
 * Output: "Palindrome"
 * 
 * Input: "race a car"
 * Output: "Not a palindrome"
 * 
 * Approach: 
 * 1. Convert string to lowercase
 * 2. Remove non-alphanumeric characters
 * 3. Compare characters from start and end moving inward
 * 
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(1) - using constant extra space
 * 
 * Test Cases:
 * - "racecar" -> Palindrome
 * - "A man a plan a canal Panama" -> Palindrome
 * - "race a car" -> Not a palindrome
 * - "hello" -> Not a palindrome
 * - "" -> Palindrome (empty string)
 * - "a" -> Palindrome (single character)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
int isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to convert character to lowercase
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

// Function to check if string is palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters from left
        while (left < right && !isAlphanumeric(str[left])) {
            left++;
        }
        
        // Skip non-alphanumeric characters from right
        while (left < right && !isAlphanumeric(str[right])) {
            right--;
        }
        
        // Compare characters (case-insensitive)
        if (toLower(str[left]) != toLower(str[right])) {
            return 0; // Not a palindrome
        }
        
        left++;
        right--;
    }
    
    return 1; // Is a palindrome
}

int main() {
    char str[1000];
    
    printf("=== Palindrome Checker ===\n");
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;
    
    if (isPalindrome(str)) {
        printf("Result: Palindrome\n");
    } else {
        printf("Result: Not a palindrome\n");
    }
    
    // Test with predefined examples
    printf("\n=== Test Cases ===\n");
    char testCases[][50] = {
        "racecar",
        "A man a plan a canal Panama",
        "race a car",
        "hello",
        "Madam",
        "12321",
        "No 'x' in Nixon"
    };
    
    for (int i = 0; i < 7; i++) {
        printf("'%s' -> %s\n", testCases[i], 
               isPalindrome(testCases[i]) ? "Palindrome" : "Not a palindrome");
    }
    
    return 0;
}
