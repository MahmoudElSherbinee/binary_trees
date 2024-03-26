#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree (BST).
 * This function searches for the given value in the binary search tree
 * (BST) rooted at the specified node.
 * If the value is found,it returns a pointer to the node containing the value;
 * otherwise, it returns NULL.
 *
 * @tree: A pointer to the root node of the binary search tree (BST).
 * @value: The value to search for in the BST.
 *
 * Return: A pointer to the node containing the value if found,
 * or NULL otherwise.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* If there's no root node, return NULL */
	if (tree == NULL)
	{
		return (NULL);
	}

	/* If the value is in the root node, return a pointer to the root node */
	if (tree->n == value)
	{
		return ((bst_t *)tree);
	}

	/* First, search for the value in the left subtree */
	/* Then, search for the value in the right subtree */
	if (tree->n > value)
	{
		return (bst_search(tree->left, value));
	}
	else
	{
		return (bst_search(tree->right, value));
	}
}
