/*
 * Data Structure: Singly Linked List
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * Description: Complete implementation of singly linked list with all basic operations
 * 
 * Operations:
 * - createNode() - Create new node
 * - insertAtBeginning() - Insert element at the beginning
 * - insertAtEnd() - Insert element at the end
 * - deleteNode() - Delete specific element
 * - search() - Search for element
 * - display() - Display list contents
 * 
 * Features:
 * - Dynamic memory allocation
 * - Complete error handling
 * - All basic operations implemented
 * 
 * Usage: gcc data_structures_linkedList.c -o linkedList && ./linkedList
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    newNode->next = head;
    return newNode;
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    
    // If head node contains the data
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    // Search for the node to delete
    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next == NULL) {
        printf("Element %d not found in the list!\n", data);
        return head;
    }
    
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to search for an element
int search(struct Node* head, int data) {
    struct Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Not found
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the entire list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    
    printf("=== Singly Linked List Operations ===\n");
    
    // Insert elements
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 30);
    
    display(head);
    
    // Search for element
    int searchResult = search(head, 20);
    if (searchResult != -1) {
        printf("Element 20 found at position %d\n", searchResult);
    } else {
        printf("Element 20 not found\n");
    }
    
    // Delete element
    head = deleteNode(head, 20);
    printf("After deleting 20: ");
    display(head);
    
    // Free memory
    freeList(head);
    
    return 0;
}
