/*
 * Application: Simple File Manager
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Description: A basic file manager that allows users to create, read, write, and manage text files
 * 
 * Features:
 * - Create new files
 * - Read file contents
 * - Write content to files
 * - List files in directory
 * - Delete files
 * - Copy files
 * 
 * Requirements:
 * - Standard C library
 * - File system access
 * 
 * Usage: gcc real_world_fileManager.c -o fileManager && ./fileManager
 * 
 * Installation:
 * - Compile with: gcc real_world_fileManager.c -o fileManager
 * - Run with: ./fileManager
 * 
 * Examples:
 * - Create a new file and write content
 * - Read and display file contents
 * - Copy files with different names
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define MAX_CONTENT 1000
#define MAX_FILES 100

// Function to create a new file
void createFile() {
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create file '%s'\n", filename);
        return;
    }
    
    printf("Enter content (type 'END' on a new line to finish):\n");
    getchar(); // Clear input buffer
    
    while (fgets(content, sizeof(content), stdin)) {
        if (strcmp(content, "END\n") == 0) {
            break;
        }
        fputs(content, file);
    }
    
    fclose(file);
    printf("File '%s' created successfully!\n", filename);
}

// Function to read file contents
void readFile() {
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];
    
    printf("Enter filename to read: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    
    printf("Contents of '%s':\n", filename);
    printf("----------------------------------------\n");
    
    while (fgets(content, sizeof(content), file)) {
        printf("%s", content);
    }
    
    printf("----------------------------------------\n");
    fclose(file);
}

// Function to append content to file
void appendToFile() {
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    
    printf("Enter content to append (type 'END' on a new line to finish):\n");
    getchar(); // Clear input buffer
    
    while (fgets(content, sizeof(content), stdin)) {
        if (strcmp(content, "END\n") == 0) {
            break;
        }
        fputs(content, file);
    }
    
    fclose(file);
    printf("Content appended to '%s' successfully!\n", filename);
}

// Function to copy file
void copyFile() {
    char source[MAX_FILENAME];
    char destination[MAX_FILENAME];
    char content[MAX_CONTENT];
    
    printf("Enter source filename: ");
    scanf("%s", source);
    
    printf("Enter destination filename: ");
    scanf("%s", destination);
    
    FILE *src = fopen(source, "r");
    if (src == NULL) {
        printf("Error: Could not open source file '%s'\n", source);
        return;
    }
    
    FILE *dest = fopen(destination, "w");
    if (dest == NULL) {
        printf("Error: Could not create destination file '%s'\n", destination);
        fclose(src);
        return;
    }
    
    while (fgets(content, sizeof(content), src)) {
        fputs(content, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("File copied from '%s' to '%s' successfully!\n", source, destination);
}

// Function to delete file
void deleteFile() {
    char filename[MAX_FILENAME];
    
    printf("Enter filename to delete: ");
    scanf("%s", filename);
    
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully!\n", filename);
    } else {
        printf("Error: Could not delete file '%s'\n", filename);
    }
}

// Function to display menu
void displayMenu() {
    printf("\n=== Simple File Manager ===\n");
    printf("1. Create new file\n");
    printf("2. Read file contents\n");
    printf("3. Append to file\n");
    printf("4. Copy file\n");
    printf("5. Delete file\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

int main() {
    int choice;
    
    printf("Welcome to Simple File Manager!\n");
    printf("This application helps you manage text files.\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                copyFile();
                break;
            case 5:
                deleteFile();
                break;
            case 6:
                printf("Thank you for using Simple File Manager!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-6.\n");
        }
    }
    
    return 0;
}
