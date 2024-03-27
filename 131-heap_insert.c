#include "binary_trees.h"

/**
 * calculate_binary_treeHeight - Recursively calculates
 * the calculate_binary_treeHeight of a binary tree.
 * This function recursively calculates the calculate_binary_treeHeight
 * of the binary tree rooted at the given node.
 * The height of a binary tree is defined as the maximum number
 * of edges between the root node and a leaf node.
 *
 * @root: A pointer to the root node of the binary tree.
 *
 * Return: The calculate_binary_treeHeight of binary tree rooted at given node
 */
int calculate_binary_treeHeight(const binary_tree_t *root)
{
	size_t height_right, height_left;

	/* Base case: If the tree is empty, its height is 0 */
	if (!root)
		return (-1);

	/* Recursively calculate the height of left subtree */
	height_left = calculate_binary_treeHeight(root->left);

	/* Recursively calculate the calculate_binary_treeHeight of right subtree */
	height_right = calculate_binary_treeHeight(root->right);

	/* Return the calculate_binary_treeHeight of the taller subtree */
	/* plus 1 (to account for the root node) */
	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}
/**
 * binary_tree_is_perfect - Checks if a binary tree is a perfect binary tree.
 * This function checks if the binary tree rooted
 * at the given node is a perfect binary tree.
 * A perfect binary tree is a binary tree in which all internal
 * nodes have two children and all leaves are at the same level.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is a perfect binary tree, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && calculate_binary_treeHeight(tree->left) ==
											calculate_binary_treeHeight(tree->right))
	{
		if (calculate_binary_treeHeight(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
		    && (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}

/**
 * swap_nodes - Swaps a parent node with a child node in a binary tree.
 *
 * This function swaps a parent node with a child
 * node in a binary tree. It is used
 * in the heap_insert function to maintain the heap
 * property after inserting a new node.
 *
 * @node_ptr: A double pointer to the parent node to be swapped.
 * @child_ptr: A double pointer to the child node to be swapped.
 */
void swap_nodes(heap_t **node_ptr, heap_t **child_ptr)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *node_ptr, child = *child_ptr;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *node_ptr = child;
	}
}


/**
 * heap_insert - Inserts a value into a binary max-heap.
 * This function inserts a new node with the given
 * value into a binary max-heap.
 * It ensures that the heap property is maintained after insertion,
 * where the parent
 * node has a value greater than or equal to its children.
 *
 * @root: A double pointer to the root node of the binary max-heap.
 * @value: The value to be inserted into the heap.a
 *
 * Return: A pointer to the newly inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	/* If the heap is empty, create a new root node */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	/* If the left subtree is perfect or not perfect, */
	/* insert into the left subtree */
	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			swap_nodes(root, &((*root)->left));
			return (new_node);
		}
		else
		{
			new_node = (*root)->left = binary_tree_node(*root, value);
			swap_nodes(root, &((*root)->left));
			return (new_node);
		}
	}
	/* If the right subtree is not NULL, insert into the right subtree */
	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		swap_nodes(root, (&(*root)->right));
		return (new_node);
	}
	/* If the right subtree is NULL, insert into the right subtree */
	else
	{
		new_node = (*root)->right = binary_tree_node(*root, value);
		swap_nodes(root, &((*root)->right));
		return (new_node);
	}
	return (NULL); /* Return NULL if insertion fails */
}
