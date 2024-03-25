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
	/* Calculate the height using the recursive function */
	/* and subtract 1 to exclude the root node */
	return (calculate_binary_tree_height(tree) - 1);
}

/**
 * binary_tree_balance - Calculates the balance factor of a binary tree.
 * This function calculates the balance factor of the binary tree
 * rooted at the given node.
 * The balance factor of a node is defined as the difference
 * between the height of its left subtree and the height of its right subtree.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The balance factor of the binary tree rooted at the given node.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* Declare and initialize variables to calculate the heights */
	int left = 0;
	int right = 0;

	/* Base case: If the tree is empty or it's a leaf node (no children),*/
	/* it has no balance factor */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	{
		return (0);
	}

	/* Calculate the height of the left subtree */
	left = binary_tree_height(tree->left);

	/* Calculate the height of the right subtree */
	right = binary_tree_height(tree->right);

	/* Balance factor = height of left subtree - height of right subtree */
	return (left - right);
}
