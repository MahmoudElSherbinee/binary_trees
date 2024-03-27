#include "binary_trees.h"


/**
 * count_nodes_in_heap - Counts the number of nodes in a binary heap.
 *
 * This function recursively traverses the binary heap rooted at the given node
 * and counts the number of nodes in it.
 *
 * @current_node: A pointer to the root of the binary heap.
 *
 * Return: The number of nodes in the binary heap.
 */
int count_nodes_in_heap(binary_tree_t *current_node)
{
	if (!current_node)
		return (0);

	return (1 + count_nodes_in_heap(current_node->left) +
			count_nodes_in_heap(current_node->right));
}

/**
 * trickle_down - Restores the heap property by trickling down a node.
 *
 * This function ensures that the binary heap property is maintained by
 * recursively swapping a node with its maximum child if necessary, until the
 * heap property is restored.
 *
 * @current_parent: A pointer to the parent node where trickling down starts.
 */
void trickle_down(heap_t *current_parent)
{
	int temprorary;

	heap_t *old_child = NULL;

	if (!current_parent)
		return;

	while (current_parent && current_parent->left)
	{
		old_child = current_parent->left;

		if (current_parent->right &&
									current_parent->right->n > current_parent->left->n)
			old_child = current_parent->right;

		if (old_child->n > current_parent->n)
		{
			temprorary = current_parent->n;
			current_parent->n = old_child->n;
			old_child->n = temprorary;
		}

		current_parent = old_child;
	}
}

/**
 * find_parent - Find the parent node of a given node in a heap.
 *
 * This function recursively searches for the parent node of a given node in a
 * binary heap based on the index of the target node. It starts from the root
 * and traverses down the heap until it finds the target node.
 *
 * @current_node:  A pointer to the current node being examined.
 * @current_index: The index of the current node in the heap.
 * @target_index:  The index of the target node for which to find the parent.
 *
 * Return: A pointer to the parent node of the target node,
 * or NULL if not found.
 */
heap_t *find_parent(heap_t *current_node, int current_index, int target_index)
{
	heap_t *left = NULL, *right = NULL;

	if (!current_node || current_index > target_index)
		return (NULL);

	if (current_index == target_index)
		return (current_node);

	left = find_parent(current_node->left, current_index * 2 + 1, target_index);
	if (left)
		return (left);

	right = find_parent(current_node->right, current_index * 2 + 2, target_index);
	if (right)
		return (right);

	return (NULL);
}

/**
 * delete_last_node - Delete the last node in a binary heap.
 *
 * This function deletes the last node in a binary heap and restores the heap
 * property by trickling down the root node.
 *
 * @tree_root:    A pointer to the root of the binary heap.
 * @parent_node:  A pointer to the parent node of the last node in the heap.
 */
void delete_last_node(heap_t **tree_root, heap_t *parent_node)
{
	heap_t *current_root = *tree_root;

	if (parent_node == current_root && !parent_node->left)
	{
		/* If the parent node is the root and has no left child */
		/* (i.e., the last node is the root). */
		free(current_root);
		*tree_root = NULL;
		return;
	}

	if (parent_node->right)
	{
		/* If the parent node has a right child, copy its value to the root, */
		/* delete the right child, and set it to NULL. */
		current_root->n = parent_node->right->n;
		free(parent_node->right);
		parent_node->right = NULL;
	}
	else if (parent_node->left)
	{
		/* If the parent node has only a left child, */
		/* do the same as above but for the left child. */
		current_root->n = parent_node->left->n;
		free(parent_node->left);
		parent_node->left = NULL;
	}

	/* Restore the heap property by trickling down the root node. */
	trickle_down(*tree_root);
}

/**
 * heap_extract - Extract the maximum value from a binary heap.
 *
 * This function extracts the maximum value from a binary heap,
 * restores the heap
 * property, and returns the extracted value.
 *
 * @root:  A pointer to the root of the binary heap.
 *
 * Return: The maximum value extracted from the heap.
 */
int heap_extract(heap_t **root)
{
	int nodes, pind = 0, max_val = 0;

	heap_t *parent;

	/* Check if the root or the heap is NULL */
	if (!root || !(*root))
		return (0);

	/* Store the maximum value (the value of the root node) */
	max_val = (*root)->n;

	/* Calculate the number of nodes in the heap */
	nodes = count_nodes_in_heap(*root);

	/* Determine the index of the parent node of the last node */
	pind = (nodes - 2) / 2;

	/* Retrieve a pointer to the parent node */
	parent = find_parent(*root, 0, pind);

	/* Remove the last node in the heap */
	delete_last_node(root, parent);

	/* Return the maximum value extracted from the heap */
	return (max_val);
}
