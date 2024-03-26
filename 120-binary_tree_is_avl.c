#include "binary_trees.h"

/**
 * check_binary_search_tree - Recursively checks if
 * a binary tree is a binary search tree (BST).
 * This function recursively checks if the binary tree
 * rooted at the given node is a binary search tree (BST).
 * It ensures that for each node, all values in its left
 * subtree are less than the node's value,
 * and all values in its right subtree are greater than the node's value.
 *
 * @root: A pointer to the root node of the binary tree.
 * @minValue: The minimum valid value for nodes in the subtree.
 * @maxValue: The maximum valid value for nodes in the subtree.
 *
 * Return: 1 if the binary tree is a binary search tree (BST), 0 otherwise.
 */
int check_binary_search_tree(const binary_tree_t *root,
							 int minValue, int maxValue)
{
	if (!root) /* If the current node is NULL */
		return (1);

	if ((root->n < minValue) || (root->n > maxValue))
		return (0);

	return (check_binary_search_tree(root->left, minValue, root->n - 1)
	&& check_binary_search_tree(root->right, root->n + 1, maxValue));
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

	/* If the balance factor less than -1 or greater than 1, return it */
	if (balFactor < -1 || balFactor > 1)
		return (balFactor);

	/* Recursively check if both left and right subtrees are balanced */
	return (calculate_tree_balance(tree->left) ||
			calculate_tree_balance(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree.
 * This function checks if the binary tree rooted
 * at the specified node is an AVL tree.
 * An AVL tree is a self-balancing binary search tree in which the
 * heights of the two child subtrees of any node differ by at most one.
 * Additionally, the function also ensures that the binary
 * tree is a binary search tree (BST) before checking for AVL property.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balanced;

	/* If the tree pointer is NULL, it cannot be an AVL tree */
	if (!tree)
		return (0);

	/* Check if the binary tree is a binary search tree (BST) */
	if (check_binary_search_tree(tree, INT_MIN, INT_MAX) == 1)
	{
		/* Determine the balance factor */
		balanced = calculate_tree_balance(tree); /* 0: balanced; 1: unbalanced */
		if (balanced == 0)
			return (1); /* The tree is AVL */
	}
	/* The tree is not AVL */
	return (0);
}
