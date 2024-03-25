#include "binary_trees.h"

/**
 * binary_tree_size - Calculates the size of a binary tree.
 * This function calculates the size of the binary tree
 * rooted at the given node.
 * The size of a binary tree is defined
 * as the total number of nodes in the tree.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The size of the binary tree rooted at the given node.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Base case: If the tree is empty, its size is 0 */
	if (tree)
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
	return (0);
}
