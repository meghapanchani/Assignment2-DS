//Part1.h file - Assignment 2
// Due Date: 15th March

#ifndef Part1_H
#define Part1_H

// Structure for a Binary Search Tree (BST) node.
typedef struct TreeNode
{
    char data;                           // Each node stores a single character.
    struct TreeNode* left, * right;      // Pointers to left and right child node.
} TreeNode;


// Function declarations (these are implemented in Part1.c).
TreeNode* createNode(char data);
TreeNode* insert(TreeNode* root, char data);
int search(TreeNode* root, char key);
int countNodes(TreeNode* root);
int treeHeight(TreeNode* root);
void inOrder(TreeNode* root);
void freeTree(TreeNode* root);

#endif