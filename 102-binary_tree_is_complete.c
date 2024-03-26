#include "binary_trees.h"

/**
 * binary_tree_size - Calculates the size of a binary tree.
 * This function calculates the size of the binary tree
 * rooted at the given node.
 * The size of a binary tree is defined
 * as the total number of nodes in the tree.
 *
 * @tree: A pointer to the tree node of the binary tree.
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

/**
 * is_complete_recursive - Recursively checks if a binary tree is complete.
 * This function recursively checks if the binary tree rooted
 * at the given node is complete.
 * A binary tree is considered complete if all levels except possibly
 * the last are completely filled,
 * and the last level is filled from left to right.
 *
 * @tree: A pointer to the tree node of the binary tree.
 * @index: The current index of the node being checked.
 * @size: The size of the binary tree.
 *
 * Return: 1 if the binary tree is complete, 0 otherwise.
 */
int is_complete_recursive(const binary_tree_t *tree, size_t index, size_t size)
{
	int left, right;

	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	left = is_complete_recursive(tree->left, (2 * index) + 1, size);
	right = is_complete_recursive(tree->right, (2 * index) + 2, size);

	if (left == 1 && right == 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is a complete binary tree.
 * This function checks if the binary tree rooted at
 * the given node is a complete binary tree.
 * A complete binary tree is a binary tree in which every level,
 * except possibly the last, is completely filled,
 * and all nodes are as far left as possible.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is a complete binary tree, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* If the tree is NULL, it cannot be complete */
	if (!tree)
		return (0);

	/* Check if the binary tree rooted at the given node is complete */
	return (is_complete_recursive(tree, 0, binary_tree_size(tree)));
}
