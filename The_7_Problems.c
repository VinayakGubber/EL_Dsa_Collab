#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to find pairs with the given sum
void findPairsWithGivenSum(int target, Node* head) {
    // Using an array to store visited values
    int visited[1000] = {0};  // Assuming values in the range [0, 999]
    Node* currNode = head;
    bool found = false;

    printf("Pairs with the given sum:\n");
    while (currNode != NULL) {
        int x = target - currNode->data;

        // Check if the required value exists in the visited array
        if (x >= 0 && visited[x]) {
            printf("%d %d\n", x, currNode->data);
            found = true;
        }

        // Mark the current value as visited
        visited[currNode->data] = 1;
        currNode = currNode->next;
    }

    if (!found) {
        printf("No pairs found.\n");
    }
}

int main() {
    // Creating a singly linked list: 1 -> 2 -> 4 -> 5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);

    int target = 7;
    findPairsWithGivenSum(target, head);

    // Free the allocated memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
