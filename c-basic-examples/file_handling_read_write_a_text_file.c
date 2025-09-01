/*
 * Topic: File Handling (Read/Write Text File)
 * Author: Surya Prakash Kahar
 * Date: 2025-09-01
 *
 * Description: Program to write text into a file and then read it back
 *
 * Prerequisites: File handling basics
 *
 * Technical Details:
 * - Uses fopen, fprintf, fscanf, fclose
 *
 * Dependencies:
 * - Standard C library (stdio.h)
 *
 * Testing:
 * - Write text to "demo.txt" and read it back
 * - Check file contents after execution
 */

#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    // Write to file
    fp = fopen("demo.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Hello, this is a file handling demo in C.\n");
    fclose(fp);

    // Read from file
    fp = fopen("demo.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("File contents:\n");
    while (fgets(text, sizeof(text), fp)) {
        printf("%s", text);
    }
    fclose(fp);

    return 0;
}
