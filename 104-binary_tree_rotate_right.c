#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * This function performs a right rotation on the binary
 * tree rooted at the given node.
 * A right rotation involves making the left child of the
 * root node the new root and adjusting the pointers accordingly.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: A pointer to the new root node after the right rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	/* Declare and initialize pointers */
	binary_tree_t *new = NULL, *root = NULL;

	/* If the root node is NULL or has no children, no rotation is needed */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (tree);

	/* Set pointer to the new root (left child of the current root) */
	new = tree->left;
	/* Set pointer to the right child of the new root */
	tree->left = new->right;
	/* If the new root's right child is not NULL, adjust its parent pointer */
	if (new->right != NULL)
		new->right->parent = tree;
	/* Swap parent pointers */
	new->parent = tree->parent;
	/* If the current root has no parent, set the new root as the tree's root */
	/* Else if the current root is the right child of its parent, */
	/* set the new root as the right child */
	/* Else set the new root as the left child of its parent */
	if (tree->parent == NULL)
		root = new;
	else if (tree == tree->parent->right)
		tree->parent->right = new;
	else
		tree->parent->left = new;
	/* Move the current root to the right of the new root */
	new->right = tree;
	tree->parent = new;
	/* Return the new root after the rotation */
	return (root ? root : new);
}
