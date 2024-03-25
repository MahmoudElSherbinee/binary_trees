#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf node.
 * This function checks if the given node is a leaf node in a binary tree.
 * A leaf node is a node that doesn't have any children.
 *
 * @node: A pointer to the node to be checked.
 *
 * Return: 1 if the node is a leaf node, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* If the given node is NULL, it cannot be a leaf node */
	if (node == NULL)
	{
		return (0);
	}

	/* If the given node doesn't have any children, it is a leaf node */
	if ((node->left == NULL) && (node->right == NULL))
	{
		return (1);
	}

	/* If the node has at least one child, it is not a leaf node */
	return (0);
}
