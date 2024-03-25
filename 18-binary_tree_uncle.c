#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * This function finds the sibling of the given node in the binary tree.
 * TheSibling of a node is another node in the tree that shares the same parent
 *
 * @node: A pointer to the node whose sibling is to be found.
 *
 * Return: A pointer to the sibling node if found,
 *			or NULL if the given node is NULL or has no parent.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If the node is NULL or it has no parent, it cannot have a sibling */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Determine if the node is the left or right child of its parent */
	if (node == node->parent->left)
	{
		/* Return the right child if the node is the left child */
		return (node->parent->right);
	}
	else
	{
		/* Return the left child if the node is the right child */
		return (node->parent->left);
	}
}

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * This function finds the uncle of the given node in the binary tree.
 * The uncle of a node is the sibling of its parent.
 *
 * @node: A pointer to the node whose uncle is to be found.
 *
 * Return: A pointer to the uncle node if found,
 *				or NULL if the given node is NULL, is the root node, or has no parent.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Base case: If the node is NULL, it cannot have an uncle */
	if (node == NULL)
	{
		return (NULL);
	}

	/* If the node is the root node or has no parent, it cannot have an uncle */
	if (node->parent == NULL)
	{
		return (NULL);
	}

	/* Check if there's a node on the same level as the parent */
	/* (i.e., the uncle) */
	return (binary_tree_sibling(node->parent));
}
