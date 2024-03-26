#include "binary_trees.h"

/**
 * IsBinarySearch_tree_recursive - Recursively checks if a binary tree
 * is a binary search tree (BST).
 * This function recursively checks if the binary tree rooted
 * at the given node is a binary search tree (BST).
 * A binary search tree is a binary tree in which for each node,
 * all values in its left subtree are less than
 * the node's value, and all values in its right subtree
 * are greater than the node's value.
 *
 * @root: A pointer to the root node of the binary tree.
 * @min: The minimum value that a node's value can take(for subtree validation)
 * @max: The maximum value that a node's value can take(for subtree validation)
 *
 * Return: 1 if the binary tree is a binary search tree (BST), 0 otherwise.
 */
int IsBinarySearch_tree_recursive(const binary_tree_t *root, int min, int max)
{
	if (!root) /* If the current node is NULL */
		return (1);

	/* If the current node's value is not within the valid range */
	if ((root->n < min) || (root->n > max))
		return (0);

	/* Recursively check left and right subtrees with updated min and max values*/
	return (IsBinarySearch_tree_recursive(root->left, min, root->n - 1) &&
	IsBinarySearch_tree_recursive(root->right, root->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST).
 * This function checks if the binary tree rooted at the
 * given node is a binary search tree (BST).
 * A binary search tree is a binary tree in which the value
 * of each node is greater than all values in its left subtree
 * and less than all values in its right subtree.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* If the tree pointer is NULL, it cannot be a BST */
	if (!tree)
		return (0);

	/* Check if the binary tree rooted at the given node is a BST */
	return (IsBinarySearch_tree_recursive(tree, INT_MIN, INT_MAX));
}
