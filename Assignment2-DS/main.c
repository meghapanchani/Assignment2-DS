#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Part1.h"

// Function to generate a random lowercase letter
// Picks a random number between 0-25, adds 'a' to it to get a letter from 'a' to 'z'.
char getRandomChar()
{
    return 'a' + (rand() % 26);
}

int main()
{
    TreeNode* root = NULL;                         // This will be our BST root node.
    srand(time(NULL));                             // Seed the random number generator with the current time.

    // Generate a random number between 11 and 20 for the number of characters to insert.
    int numChars = 11 + (rand() % 10);

    // Allocate memory dynamically to store the characters we insert.
    char* charsInserted = (char*)malloc(numChars * sizeof(char));

    // Check if memory allocation was successful.
    if (charsInserted == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;                                // Exit the program if memory allocation fails.
    }

    printf("Inserting %d random characters into BST: ", numChars);

    // Insert the randomly generated characters into the BST.
    for (int i = 0; i < numChars; i++)
    {
        char randomChar = getRandomChar();       // Generate a random character.
        charsInserted[i] = randomChar;           // Store it in our array.
        root = insert(root, randomChar);         // Insert into BST.
        printf("%c ", randomChar);               // Print the inserted character.
    }

    // Print the tree's contents in sorted order using in-order traversal.
    printf("\n\nSorted characters (in-order traversal): ");
    inOrder(root);

    // Print the total number of nodes in the BST.
    printf("\n\nTotal number of nodes: %d", countNodes(root));

    // Print the height of the BST.
    printf("\nTree height: %d\n", treeHeight(root));

    // Free dynamically allocated memory.
    free(charsInserted);
    freeTree(root);                              // Also free the tree nodes.

    return 0;
}