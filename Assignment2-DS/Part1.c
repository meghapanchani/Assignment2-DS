// Part1.c file - Assignment 2
// Due Date: 15th March

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a BST node.
typedef struct TreeNode
{
    char data;
    struct TreeNode* left, * right;
} TreeNode;


// Function to create a new node.
// Allocates memory and initializes the node with given data.
TreeNode* createNode(char data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;          // New nodes have no children at first.
    return newNode;
}


// Function to insert a character into the BST.
TreeNode* insert(TreeNode* root, char data)
{
    if (root == NULL)
    {
        return createNode(data);                    // If tree is empty, create a new node.
    }
    if (data < root->data)                          // If the new character is smaller, insert into left subtree.
    {
        root->left = insert(root->left, data);
    }
    else                                            // Otherwise, insert into the right subtree.
    {
        root->right = insert(root->right, data);
    }
    return root;
}


// Function to search for a character in the BST.
int search(TreeNode* root, char key)
{
    if (root == NULL)
    {
        return 0;                                   // If we reach a NULL node, the character is not found.
    }
    if (root->data == key)
    {
        return 1;                                   // Found the character.
    }
    if (key < root->data)
    {
        return search(root->left, key);             // Search in the left subtree.
    }
    return search(root->right, key);                // Search in the right subtree.
}


// Function to count the number of nodes in the BST.
int countNodes(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;                                   // Base case: empty tree has 0 nodes.
    }
    // Recursively count left and right subtree nodes and add 1 for the current node.
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Function to determine the height of the BST.
// The height is the longest path from the root to a leaf.
int treeHeight(TreeNode* root)
{
    if (root == NULL)
    {
        return -1;                                   // Convention: Empty tree has height -1.
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}


// Function to print the BST in sorted order using in-order traversal.
void inOrder(TreeNode* root)
{
    if (root != NULL)
    {
        inOrder(root->left);                          // Visit left subtree.
        printf("%c ", root->data);                   // Print current node.
        inOrder(root->right);                        // Visit right subtree.
    }
}


// Function to free the allocated memory for the BST.
// This avoids memory leaks by freeing nodes recursively.
void freeTree(TreeNode* root)
{
    if (root != NULL)
    {
        freeTree(root->left);                       // Free left subtree.
        freeTree(root->right);                      // Free right subtree.
        free(root);                                 // Free current node.
    }
}