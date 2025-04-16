// Renard Kombo
// R#: 11786591

// Lab 3 
// 4/15/2025

// PART 1 

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

// main funct.
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    // allocate for max 100 nodes 
    int* result = (int*)malloc(100 * sizeof(int)); 
    preorder(root, result, returnSize);
    return result;
}

//////////////////////////////////////////////////////////////////////
//                    Run separately                                //
//////////////////////////////////////////////////////////////////////

// PART 2

#include <stdlib.h>

// binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// recursive funct.
void inorder(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    inorder(root->left, result, returnSize);
    result[(*returnSize)++] = root->val;
    inorder(root->right, result, returnSize);
}

// main function
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    // allocate for max 100 nodes
    int* result = (int*)malloc(100 * sizeof(int)); 
    inorder(root, result, returnSize);
    return result;
}
