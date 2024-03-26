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
	/* Check if the parent node exists */
	if (parent == NULL)
		return (NULL);

	/* Declare and initialize a new node */
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	/* Initialize the new node */
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	/* If the parent already has a left child */
	if (parent->left != NULL)
	{
		/* Set the new node's left child to the parent's current left child */
		new->left = parent->left;
		/* Update the parent pointer of the existing */
		/* left child to point to the new node */
		parent->left->parent = new;
	}

	/* Set the parent's left child to the new node */
	parent->left = new;

	/* Return a pointer to the newly inserted node */
	return (new);
}
