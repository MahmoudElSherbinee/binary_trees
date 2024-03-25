#include "binary_trees.h"

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
	left = calculate_binary_tree_height(tree->left) - 1;

	/* Calculate the height of the right subtree */
	right = calculate_binary_tree_height(tree->right) - 1;

	/* Balance factor = height of left subtree - height of right subtree */
	return (left - right);
}

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
 * calculate_tree_balance - Recursively checks if a binary tree is balanced.
 * This function recursively checks if the binary tree rooted
 * at the given node is balanced.
 * A balanced binary tree is a binary tree in which
 * the balance factor of every node is either -1, 0, or 1.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The balance factor of the binary tree if it's not balanced,
 * otherwise it returns 0.
 */
int calculate_tree_balance(const binary_tree_t *tree)
{
	int balFactor;

	/* Base case: If the tree is empty, it is considered balanced */
	if (!tree)
		return (0);

	/* Calculate the balance factor of the current node */
	balFactor = binary_tree_balance(tree);

	/* If the balance factor is not 0, return it */
	if (balFactor != 0)
		return (balFactor);

	/* Recursively check if both left and right subtrees are balanced */
	return (calculate_tree_balance(tree->left) ||
												calculate_tree_balance(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is a perfect binary tree.
 * This function checks if the binary tree rooted
 * at the given node is a perfect binary tree.
 * A perfect binary tree is a binary tree in which all internal
 * nodes have two children and all leaves are at the same level.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is a perfect binary tree, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* Base case: If the tree is empty, it cannot be perfect */
	if (tree == NULL)
		return (0);

	/* Check if all nodes in the binary tree have a balance factor of 0 */
	if (calculate_tree_balance(tree) == 0)
		return (1);

	return (0);
}
