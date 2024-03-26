#include "binary_trees.h"

/**
 * bst_insert_recursive - Recursively inserts a value into
 * a binary search tree (BST).
 * This function recursively inserts a value into the
 * binary search tree rooted at the given node.
 *
 * @root: A pointer to the root node of the binary search tree.
 * @value: The value to be inserted into the binary search tree.
 *
 * Return: A pointer to the node where the value was inserted,
 * or NULL if the value already exists in the tree.
 */
bst_t *bst_insert_recursive(bst_t *root, int value)
{
	if (!root) /* If the current node is NULL */
		return (NULL);

	/* If the value is less than the value in the current node */
	if (value < root->n)
	{
		if (root->left != NULL)
			return (bst_insert_recursive(root->left, value));
		else
			return (root);
	}

	/* If the value is greater than the value in the current node */
	else if (value > root->n)
	{
		if (root->right != NULL)
		{
			return (bst_insert_recursive(root->right, value));
		}
		else
			return (root);
	}

	/* If the value already exists in the tree */
	return (NULL);
}

/**
 * bst_insert - Inserts a value into a binary search tree (BST).
 * This function inserts a new node with the given
 * value into the binary search tree (BST).
 * If the tree is empty, it creates a new tree with the given value as the root
 * If the value already exists in the tree, no action is taken.
 *
 * @tree: A pointer to a pointer to the root node of the BST.
 * @value: The value to be inserted into the BST.
 *
 * Return: A pointer to the newly inserted nodeIf successful,or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *parent = NULL;

	/* Check if the pointer to the tree pointer is NULL */
	if (tree == NULL)
		return (NULL);

	/* If the tree doesn't exist, create a new tree */
	/* with the given value as the root */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	/* Find the parent node for the new node */
	parent = bst_insert_recursive(*tree, value);

	/* If the parent node was found, create a new node */
	if (parent)
		new_node = binary_tree_node(parent, value);
	else
		return (NULL);

	/* Point the parent node to the new node */
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
