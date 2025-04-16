// Renard Kombo
// R#: 11786591

// Lab 3 part 1
// 4/15/2025

#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// preorder traversal function
void preorder(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    result[(*returnSize)++] = root->val;
    preorder(root->left, result, returnSize);
    preorder(root->right, result, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    // allocate for max 100 nodes 
    int* result = (int*)malloc(100 * sizeof(int)); 
    preorder(root, result, returnSize);
    return result;
}

//////////////////////////////////////////////////////////////////////

