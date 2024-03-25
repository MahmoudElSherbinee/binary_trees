#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaf nodes in a binary tree.
 * This function counts the number of leaf nodes
 * in the binary tree rooted at the given node.
 * A leaf node is a node that doesn't have any children.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The number of leaf nodes in the binary tree rooted at the given node
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* Declare and initialize variable for leaves */
	size_t leaves = 0;

	/* Base case: If the tree is empty, it has no leaves */
	if (tree == NULL)
	{
		return (0);
	}

	/* If the given node is a leaf node */
	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (1);
	}

	/* Recursively count the leaf nodes in the left and right subtrees */
	leaves = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	return (leaves);
}
