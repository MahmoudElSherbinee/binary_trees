#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal on a binary tree.
 * This function traverses the binary tree in in-order fashion,
 * which means it visits the left subtree,
 * then the root node, and finally the right subtree.
 * For each visited node, the given function pointer
 * is called with the value of the node as an argument.
 *
 * @tree: A pointer to the root node of the binary tree to be traversed.
 * @func: A pointer to the function
 *					that will be called for each visited node,
 *						with the value of the node as an argument.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* If either pointer is NULL, return */
	if (!tree || !func)
		return;

	/* Recursively traverse the left subtree */
	binary_tree_inorder(tree->left, func);

	/* Call the function with the value of the current node */
	func(tree->n);

	/* Recursively traverse the right subtree */
	binary_tree_inorder(tree->right, func);
}
