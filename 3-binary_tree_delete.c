#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * This function recursively deletes all nodes in the binary tree
 * starting from the given root node.
 * It frees the memory allocated for each node and its descendants.
 *
 * @tree: A pointer to the root node of the binary tree to be deleted.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* Check if the tree is not empty */
	if (tree)
	{
		/* Recursively delete the left subtree */
		binary_tree_delete(tree->left);

		/* Recursively delete the right subtree */
		binary_tree_delete(tree->right);

		/* Free the memory allocated for the current node */
		free(tree);
	}
}
