#include "binary_trees.h"

/**
* find_leftmost_node - Finds the leftmost node in a binary search tree.
* This function finds the leftmost node in the
* binary search tree rooted at the given node.
* The leftmost node is the node with the smallest value in the tree.
*
* @root: A pointer to the root node of the binary search tree.
*
* Return: A pointer to the leftmost node in the binary search tree,
* or NULL if the tree is empty.
*/
bst_t *find_leftmost_node(bst_t *root)
{
	bst_t *current = root;

	while ((current) && (current->left))
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node with a specific value
 * from a binary search tree (BST).
 * This function removes a node with the specified value
 * from the binary search tree (BST) rooted at the given node.
 * If the value is found in the tree, the node containing
 * the value is removed and the tree is adjusted accordingly
 * to maintain the BST property.
 *
 * @root: A pointer to the root node of the binary search tree (BST).
 * @value: The value to be removed from the BST.
 *
 * Return: A pointer to the root node of the modified
 * BST after the removal operation.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new = NULL; /* Declare and initialize pointer */

	if (root == NULL) /* If there's no root node or no given value */
		return (root);
	if (root->n > value) /* First,searchFor value in left subtree, Then right */
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else if (root->n == value)
	{	/* If there's no children, simply free the node and return NULL */
		if (root->left == NULL && root->right == NULL)
		{	free(root);
			return (NULL);
		}
		if (root->left == NULL)
		{	new = root->right;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new;
				else
					root->parent->right = new;
			}
			new->parent = root->parent;
			free(root);
			return (new);
		}
		else if (root->right == NULL)
		{	new = root->left;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new;
				else
					root->parent->right = new;
			}
			new->parent = root->parent;
			free(root);
			return (new);
		}
		else 	/* If there are two children, replace the node's value */
		{	new = find_leftmost_node(root);
			root->n = new->n;
			root->right = bst_remove(root->right, new->n);
		}
	}
	return (root);
}
