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