#include "binary_trees.h"
/**
* find_inorder_successor - Finds the inorder successor of a node
* in a binary search tree.
* This function finds the inorder successor of the given node
* in the binary search tree.
* The inorder successor of a node is the node with the smallest key
* greater than the key of the given node.
*
* @node: A pointer to the node whose inorder successor needs to be found.
*
* Return: The value of the inorder successor,
* or 0 if the node is NULL or if there is no successor.
*/
int find_inorder_successor(bst_t *node)
{
	int left_successor = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_successor = find_inorder_successor(node->left);
		if (left_successor == 0)
		{
			return (node->n);
		}
		return (left_successor);
	}
}


/**
* replace_with_inorder_successor - Replaces a node with two children
* in a binary search tree with its inorder successor.
* This function replaces a node with two children in a binary search tree
* with its inorder successor.
* The inorder successor of a node is the node with the smallest key
* greater than the key of the given node.
*
* @root: A pointer to the root node of the binary search tree.
*
* Return: The value of the inorder successor that replaced the node,
* or 0 if the node has no right child.
*/
int replace_with_inorder_successor(bst_t *root)
{
	int new_value = 0;

	if (root->right == NULL)
		return (0);

	new_value = find_inorder_successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
* remove_node - Removes a node from a binary search tree based on its type.
*
* This function removes a node from a binary search tree
* based on its type (whether it has zero, one, or two children).
*
* @root: A pointer to the node to be removed from the binary search tree.
*
* Return: The value of the inorder successor that replaced the removed node,
* or 0 if the removed node had no right child.
*/
int remove_node(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (replace_with_inorder_successor(root));
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
* Return: A pointer to the root node of the modified BST
* after the removal operation.
*/
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	/* If the root node is NULL, return NULL */
	if (root == NULL)
		return (NULL);

	/* If the value is less than the value of the root node, */
	/* remove it from the left subtree */
	if (value < root->n)
		bst_remove(root->left, value);
	/* If the value is greater than the value of the root node, */
	/* remove it from the right subtree */
	else if (value > root->n)
		bst_remove(root->right, value);
	/* If the value is equal to the value of the root node */
	else if (value == root->n)
	{
		/* Determine the type of removal */
		type = remove_node(root);
		/* If the type is not zero, remove the node with the specified type */
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}
