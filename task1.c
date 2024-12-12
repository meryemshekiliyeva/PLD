#include "main.h"
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
void printReverseRecursive(struct ListNode* head) {
    	if (head == NULL) {
        	return;
}
	printReverseRecursive(head->next);
    	printf("%d ", head->val);
}
void printReverseNonRecursive(struct ListNode* head) {
    int nodeCount = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        nodeCount++;
        current = current->next;
    }
    struct ListNode** stack = (struct ListNode**)malloc(nodeCount * sizeof(struct ListNode*));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    current = head;
    int index = 0;
    while (current != NULL) {
        stack[index++] = current;
        current = current->next;
    }

	   for (int i = nodeCount - 1; i >= 0; i--) {
        	printf("%d ", stack[i]->val);
    }
    printf("\n");
    free(stack);
}
