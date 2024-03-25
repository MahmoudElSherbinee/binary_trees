#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs a post-order traversal on a binary tree.
 *
 * This function traverses the binary tree in post-order fashion,
 * which means it visits the left subtree, then the right subtree,
 * and finally the root node.
 * For each visited node, the given function pointer is called with the value
 * of the node as an argument.
 *
 * @tree: A pointer to the root node of the binary tree to be traversed.
 * @func: A pointer to the function that will be called for each visited node,
 * with the value of the node as an argument.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Base case: If the tree or the function pointer is NULL, do nothing */
	if ((tree == NULL) || (func == NULL))
	{
		;
	}

	/* Recursively traverse the tree in post-order fashion */
	else
	{
		/* Recursively traverse the left subtree */
		binary_tree_postorder(tree->left, func);

		/* Recursively traverse the right subtree */
		binary_tree_postorder(tree->right, func);

		/* Call the function with the value of the current node */
		func(tree->n);
	}
}
