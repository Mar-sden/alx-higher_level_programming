#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to check if a linked list has a cycle
int check_cycle(Node* list) {
    Node* slow = list; // Slow pointer moves one step at a time
    Node* fast = list; // Fast pointer moves two steps at a time

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If there is a cycle, the fast pointer will eventually catch up with the slow pointer
        if (slow == fast) {
            return 1; // Cycle detected
        }
    }

    return 0; // No cycle found
}

// Test the function
int main() {
    // Create a linked list with a cycle
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = head; // Create a cycle by pointing the last node to the head

    // Call the function to check for a cycle
    int hasCycle = check_cycle(head);

    // Print the result
    printf("The linked list %s a cycle.\n", hasCycle ? "has" : "does not have");

    // Clean up the memory
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}

