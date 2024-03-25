#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node
 * as the right child of a given node.
 * This function inserts a new node with the specified value
 * as the right child of the given parent node.
 * If the parent node already has a right child,
 * the new node becomes the right child,
 * and the existing right child becomes the right child of the new node.
 *
 * @parent: A pointer to the parent node where the new node
 * will be inserted as the right child.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly inserted binary tree node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* Declare a pointer to the right child and initialize it to NULL */
	binary_tree_t *right_child = NULL;

	/* If there is no parent, return NULL */
	if (parent == NULL)
		return (NULL);

	/* Allocate memory for the right child */
	right_child = malloc(sizeof(binary_tree_t));
	if (right_child == NULL)
		return (NULL);

	/* Assign values to the right child */
	right_child->n = value;
	right_child->left = NULL;
	right_child->right = NULL;
	right_child->parent = parent;

	/* If the parent already has a right child */
	if (parent->right != NULL)
	{
		/* Set the right child of the new node to the parent's current right child */
		right_child->right = parent->right;
		/* Update the parent pointer of the existing */
		/* right child to point to the new node */
		(parent->right)->parent = right_child;
	}

	/* Set the parent's right child to the new node */
	parent->right = right_child;

	/* Return a pointer to the newly inserted node */
	return (right_child);
}
