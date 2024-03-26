#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * This function performs a left rotation on the
 * binary tree rooted at the given node.
 * A left rotation involves making the right child
 * of the root node the new root and adjusting the pointers accordingly.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: A pointer to the new root node after the left rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	/* Declare and initialize pointers */
	binary_tree_t *new = NULL, *root = NULL;

	/* If the root node is NULL or has no children, no rotation is needed */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (tree);

	/* Set pointer to the new root (right child of the current root) */
	new = tree->right;
	/* Set pointer to the left child of the new root */
	tree->right = new->left;
	/* If the new root's left child is not NULL, adjust its parent pointer */
	if (new->left != NULL)
		new->left->parent = tree;
	/* Swap parent pointers */
	new->parent = tree->parent;
	/* If the current root has no parent, set the new root as the tree's root */
	/* Else if the current root is the left child of its parent, */
	/* set the new root as the left child */
	/* Else set the new root as the right child of its parent */
	if (tree->parent == NULL)
		root = new;
	else if (tree == tree->parent->left)
		tree->parent->left = new;
	else
		tree->parent->right = new;
	/* Move the current root to the left of the new root */
	new->left = tree;
	tree->parent = new;
	/* Return the new root after the rotation */
	return (root ? root : new);
}
