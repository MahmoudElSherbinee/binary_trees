#include "binary_trees.h"

/**
 * insert_avl_node - Inserts a node with a specified value into an AVL tree.
 * This function inserts a new node with the specified value
 * into the AVL tree rooted at the specified root node.
 * If the root of the AVL tree is NULL, a new AVL tree with
 * the given value as its root is created.
 * The function recursively traverses the AVL tree to find
 * the appropriate position for the new node insertion.
 * After insertion, it checks the balance factor of the AVL
 * tree and performs rotations if necessary to maintain AVL balance.
 *
 * @root: A double pointer to the root node of the AVL tree.
 * @parent: A pointer to the parent node of the current node being examined.
 * @new_node: A double pointer to the new node to be inserted into the AVL tree
 * @value: The value to be inserted into the AVL tree.
 *
 * Return: A pointer to the root node of the AVL tree after the insertion,
 * or NULL if the new node could not be inserted.
 */
/* If the root of the AVL tree is NULL, */
	/* create a new AVL tree with the given value as its root */
avl_t *insert_avl_node(avl_t **root, avl_t *parent,
												avl_t **new_node, int value)
{
	int balance_factor;

	if (*root == NULL)
		return (*new_node = binary_tree_node(parent, value));
	/* If the value is less than the value in the current node, */
	/* insert into the left subtree */
	if ((*root)->n > value)
	{	/* Recursively insert into the left subtree */
		(*root)->left = insert_avl_node(&(*root)->left, *root, new_node, value);
		if ((*root)->left == NULL) /* Check if the left insertion failed */
			return (NULL);
	}
	/* If the value is greater than the value in the current node, */
	/* insert into the right subtree */
	else if ((*root)->n < value)
	{	(*root)->right = insert_avl_node(&(*root)->right, *root, new_node, value);
		if ((*root)->right == NULL)
			return (NULL);
	}
	else
		return (*root); /* Value already exists in the AVL tree */
	/* Calculate the balance factor of the current node */
	balance_factor = binary_tree_balance(*root);

	/* Perform rotations to maintain AVL balance */
	if (balance_factor > 1 && (*root)->left->n > value)
	{	*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor > 1 && (*root)->left->n < value)
	{	(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n < value)
	{	*root = binary_tree_rotate_left(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n > value)
	{	(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}
	return (*root);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * This function inserts a new node with the specified value
 * into the AVL tree rooted at the specified node.
 * If the AVL tree is empty, a new AVL tree
 * with the given value as its root is created.
 * The function then inserts the new value into the AVL tree
 * using a helper recursive function.
 * After insertion, it performs any necessary
 * rotations to rebalance the AVL tree.
 *
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to be inserted into the AVL tree.
 * Return: A pointer to the newly inserted node in the AVL tree,
 * or NULL if insertion fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	/* If the AVL tree is empty, */
	/* create a new AVL tree with the given value as its root */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* Insert the new value into the AVL tree using a helper recursive function */
	insert_avl_node(tree, *tree, &new, value);

	return (new);
}
