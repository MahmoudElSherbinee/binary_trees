#include "binary_trees.h"

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


/**
 * is_heap - Checks if a binary tree is a max-heap.
 * This function recursively checks if the given binary tree is a max-heap.
 * A max-heap is a complete binary tree where every node has a value greater
 * than or equal to the values of its children nodes.
 *
 * @node: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a max-heap, 0 otherwise.
 */
int is_heap(const binary_tree_t *node)
{
	/* Base case: if node is NULL, return 0 */
	if (node == NULL)
		return (0);

	/* Base case: if node has no children, return 1 */
	if (node->left == NULL && node->right == NULL)
		return (1);

	/* Base case: if node has no right child, */
	/* check if it's greater than its left child */
	if (node->right == NULL)
		return (node->n >= node->left->n);

	/* Recursive case: check if node's value is */
	/* greater than or equal to its children's values */
	if (node->n >= node->left->n && node->n >= node->right->n)
		return (is_heap(node->left) && is_heap(node->right));

	return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max-heap.
 * This function checks if the given binary tree is a max-heap.
 * It first verifies if the tree is a complete binary tree
 * using the `binary_tree_is_complete` function,
 * and then checks if every node in the tree
 * is greater than or equal to its children
 * using the `is_heap` function.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a max-heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	/* Check if the tree is a complete binary tree */
	/* and if every node is greater than or equal to its child */
	if (binary_tree_is_complete(tree) && is_heap(tree))
		return (1);
	return (0);
}
