#include "binary_trees.h"

/**
 * balance_avl_tree - Balances an AVL tree.
 * This function balances the AVL tree rooted at the specified node
 * by performing rotations as needed.
 * It recursively traverses the AVL tree in postorder fashion,
 * calculating the balance factor for each node.
 * If the balance factor of a node indicates that it is unbalanced,
 * the appropriate rotation is applied.
 *
 * @root: A double pointer to the root node of the AVL tree.
 */
void balance_avl_tree(avl_t **root)
{
	int balance_factor;

	/* Check if root is NULL or if tree has only one node */
	if (root == NULL || *root == NULL ||
	((*root)->left == NULL && (*root)->right == NULL))
		return;

	/* Recursively balance the left subtree */
	balance_avl_tree(&(*root)->left);

	/* Recursively balance the right subtree */
	balance_avl_tree(&(*root)->right);

	/* Calculate the balance factor of the current node */
	balance_factor = binary_tree_balance((const binary_tree_t *)*root);

	/* If the balance factor indicates left-heavy, perform a right rotation */
	if (balance_factor > 1)
		*root = binary_tree_rotate_right((binary_tree_t *)*root);
	/* If the balance factor indicates right-heavy, perform a left rotation */
	else if (balance_factor < -1)
		*root = binary_tree_rotate_left((binary_tree_t *)*root);
}

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
	int new_value = 0;

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
	{
		new_value = find_inorder_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
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

/**
 * avl_remove - Removes a node with the specified value from an AVL tree.
 * This function removes a node with the specified value from the AVL tree
 * rooted at the specified node.
 * It first removes the node using the bst_remove function,
 * which handles the removal of nodes from binary search trees.
 * After removal, it ensures that the AVL tree remains
 * balanced by calling the bal function to rebalance the tree.
 *
 * @root: A pointer to the root node of the AVL tree.
 * @value: The value of the node to be removed.
 *
 * Return: A pointer to the root node of the AVL tree after removal,
 * or NULL if the node with the specified value does not exist.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tree = (avl_t *)bst_remove((bst_t *)root, value);

	/* If removal fails, return NULL */
	if (tree == NULL)
		return (NULL);

	/* Rebalance the AVL tree */
	balance_avl_tree(&tree);

	return (tree);
}
