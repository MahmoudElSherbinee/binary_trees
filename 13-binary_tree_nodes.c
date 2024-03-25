#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree.
 * This function counts the number of nodes
 * in the binary tree rooted at the given node.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The number of nodes in the binary tree rooted at the given node.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Base case: If the tree is empty or it's */
	/* a leaf node (no children), it has no nodes */
	if (tree && (tree->left || tree->right))
		return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
	return (0);
}
