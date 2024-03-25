#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree.
 * This function calculates the depth of the given node in the binary tree.
 * The depth of a node is defined as the number
 * of edges between the node and the root node.
 *
 * @tree: A pointer to the node whose depth is to be calculated.
 *
 * Return: The depth of the given node in the binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* Declare and initialize variable for depth */
	size_t depth = 0;

	/* Base case: If the tree is NULL, its depth is 0 */
	if (tree == NULL)
	{
		return (0);
	}

	/* Iterate through the path to the root */
	while (tree)
	{
		tree = tree->parent; /* Move to the parent node */
		depth++;			 /* Increment the depth */
	}

	/* Subtract 1 to exclude the root node from the depth calculation */
	return (depth - 1);
}
