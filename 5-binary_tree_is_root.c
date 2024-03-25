#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root node.
 *
 * This function checks if the given node is a root node in a binary tree.
 * A root node is a node that doesn't have a parent.
 *
 * @node: A pointer to the node to be checked.
 *
 * Return: 1 if the node is a root node, 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* If the node is not NULL */
	if (node != NULL)
	{
		/* If the node doesn't have a parent, it is a root node */
		if (node->parent == NULL)
		{
			return (1);
		}
	}
	/* If the node is NULL or has a parent, it is not a root node */
	return (0);
}
