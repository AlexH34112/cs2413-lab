/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode *node, long min, long max) {
    if (node == NULL) {
        return 0;
    }
    if ((node->val <= min) || (node->val >= max)) {
        return -1;
    }
    int leftHeight = height(node->left, min, node->val);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = height(node->right, node->val, max);
    if (rightHeight == -1) {
        return -1;
    }
    if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1) {
        return -1;
    }
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } 
    else 
    {
        return rightHeight + 1;
    }
}
bool isAVL(struct TreeNode* root) {
    if (height(root, -2147483649L, 2147483648L) == -1) {
        return false;
    }
    return true;
}