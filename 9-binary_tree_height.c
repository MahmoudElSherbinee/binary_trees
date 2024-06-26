#include "binary_trees.h"

/**
 * calculate_binary_tree_height - Recursively calculates
 * the height of a binary tree.
 * This function recursively calculates the height
 * of the binary tree rooted at the given node.
 * The height of a binary tree is defined as the maximum number
 * of edges between the root node and a leaf node.
 *
 * @root: A pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree rooted at the given node.
 */
size_t calculate_binary_tree_height(const binary_tree_t *root)
{
	size_t height_right, height_left;

	/* Base case: If the tree is empty, its height is 0 */
	if (!root)
		return (0);

	/* Recursively calculate the height of the left subtree */
	height_left = calculate_binary_tree_height(root->left);

	/* Recursively calculate the height of the right subtree */
	height_right = calculate_binary_tree_height(root->right);

	/* Return the height of the taller subtree */
	/* plus 1 (to account for the root node) */
	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 *
 * This function calculates the height of the binary tree
 * rooted at the given node.
 * The height of a binary tree is defined as the maximum number
 * of edges between the root node and a leaf node.
 *
 * @tree: A pointer to the root node of the binary tree.
 * Return: The height of the binary tree rooted at the given node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* If the tree is empty, its height is 0 */
	if (!tree)
		return (0);

	/* Calculate the height using the recursive function */
	/* and subtract 1 to exclude the root node */
	return (calculate_binary_tree_height(tree) - 1);
}
