#include <stdio.h>
#include <stdlib.h>

// Define the ListNode structure
struct ListNode {
    int val;
    struct ListNode* next;
};

// Non-recursive function to print the list in reverse
void printReverseNonRecursive(struct ListNode* head) {
    // Initialize a stack (using dynamic array or linked list, here we use a simple array)
    int stack[1000];  // Assuming the list won't exceed 1000 nodes
    int top = -1;

    // Traverse the list and push the values onto the stack
    struct ListNode* current = head;
    while (current != NULL) {
        stack[++top] = current->val;
        current = current->next;
    }
	     while (top >= 0) {
        	printf("%d ", stack[top--]);
    }
}
