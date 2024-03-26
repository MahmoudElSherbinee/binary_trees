#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node
 * as the left child of a given node.
 * This function inserts a new node with the specified value
 * as the left child of the given parent node.
 * If the parent node already has a left child,
 * the new node becomes the left child,
 * and the existing left child becomes the left child of the new node.
 *
 * @parent: A pointer to the parent node where the new
 * node will be inserted as the left child.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly inserted binary tree node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (parent == NULL)
		return (NULL);

	/* create new node */
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	/* initialize new node */
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	/* if parent already has left node */
	if (parent->left != NULL)
	{
		new->left = parent->left; /* old left is now new's left */
		parent->left->parent = new; /* set old left's parent to new */
	}
	parent->left = new; /* point parent's left to new node */

	return (new);
}
