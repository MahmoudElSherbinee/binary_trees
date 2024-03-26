#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node.
 * This function creates a new binary tree node
 * with the specified value and parent node.
 *
 * @parent: A pointer to the parent node of the new node.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created binary tree node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Allocate memory for the new node */
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	/* Set the value and parent of the new node */
	new->n = value;
	new->parent = parent;

	/* Set left and right children to NULL */
	new->left = NULL;
	new->right = NULL;

	/* Return a pointer to the newly created node */
	return (new);
}
