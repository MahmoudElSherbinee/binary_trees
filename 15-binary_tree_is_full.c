#include "binary_trees.h"

/**
 * is_binary_tree_full - Recursively checks if a binary tree is full.
 * A binary tree is considered full if every node
 * has either zero or two children.
 *
 * @root: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is full, 0 otherwise.
 */
int is_binary_tree_full(const binary_tree_t *root)
{
	/* Base case: If the tree is empty, it is considered full */
	if (!root)
		return (1);

	/* If the current node is a leaf node, */
	/* it satisfies the condition of being full */
	if (!root->left && !root->right)
		return (1);

	/* If the current node has only one child, it is not a full binary tree */
	if (!root->left || !root->right)
		return (0);

	/* Recursively check if both left and right subtrees are full */
	return (is_binary_tree_full(root->left) && is_binary_tree_full(root->right));
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * This function checks if the binary tree rooted
 * at the given node is a full binary tree.
 * A full binary tree is a binary tree in which every node other than
 * the leaves has two children.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If the tree is empty, it cannot be full */
	if (!tree)
		return (0);

	/* Check if the binary tree rooted at the given node is full */
	return (is_binary_tree_full(tree));
}
