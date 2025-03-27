
<-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -->

   //IN OPTIMAL APPROACH CODE:
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int data;
 struct Node* next;
 struct Node* prev;
} Node;
typedef struct DoublyLinkedList {
 Node* head;
 Node* tail;
} DoublyLinkedList;
Node* createNode(int data) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 newNode->prev = NULL;
 return newNode;
}
void addNode(DoublyLinkedList* dll, int data) {
Node* newNode = createNode(data);
 if (dll->head == NULL) {
 dll->head = dll->tail = newNode;
 } else {
 dll->tail->next = newNode;
 newNode->prev = dll->tail;
 dll->tail = newNode;
 }
}
void findPairsWithSum(DoublyLinkedList* dll, int target) {
 if (dll->head == NULL || dll->tail == NULL) {
 printf("The list is empty or has only one element.\n");
 return;
 }
 Node* left = dll->head;
Node* right = dll->tail;
 printf("Pairs with sum %d:\n", target);
 int found = 0;
while (left != NULL && right != NULL && left != right && left->next != right) {
 int sum = left->data + right->data;
if (sum == target) {
printf("(%d, %d)\n", left->data, right->data);
 found = 1;
 left = left->next;
 right = right->prev;
 } else if (sum < target) {
 left = left->next;
 } else {
 right = right->prev;
 }
 }
 if (!found) {
 printf("No pairs found.\n");
 }
}
int main() {
 DoublyLinkedList dll;
 dll.head = NULL;
 dll.tail = NULL;




addNode(&dll, 1);
 addNode(&dll, 2);
 addNode(&dll, 4);
 addNode(&dll, 5);
 addNode(&dll, 6);
 addNode(&dll, 8);
 addNode(&dll, 9);
int target = 10;

findPairsWithSum(&dll, target);
 Node* temp;
 while (dll.head != NULL) {
 temp = dll.head;
 dll.head = dll.head->next;
 free(temp);
 }
 return 0;
}





//INORDER 
//OPTIMAL CODE:
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
 int val;
 struct TreeNode* left;
 struct TreeNode* right;
} TreeNode;
TreeNode* createNode(int value) {
 TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
 newNode->val = value;
 newNode->left = newNode->right = NULL;
return newNode;
}
void inorder(TreeNode* root) {
 if (root == NULL) return;
inorder(root->left);
 printf("%d ", root->val);
inorder(root->right);
}
int main() {
 TreeNode* root = createNode(3);
 root->left = createNode(2);
 root->right = createNode(4);
 root->left->left = createNode(1);
 root->left->right = createNode(5);
 root->right->left = createNode(6);
 root->right->right = createNode(8);
 inorder(root); // Output: 1 2 5 3 6 4 8
 return 0;
}