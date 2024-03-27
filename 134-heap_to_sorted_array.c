#include "binary_trees.h"

/**
* count_nodes - Count the number of nodes in a binary tree.
*
* This function recursively counts the number of nodes in a binary tree.
*
* @current_node: ointer to the current node.
*
* Return: The number of nodes in the binary tree.
*/
int count_nodes(binary_tree_t *current_node)
{
	/* If the current node is NULL, return 0 */
	if (!current_node)
		return (0);

	/* Recursively count nodes in the left subtree */
	int left_count = count_nodes(current_node->left);

	/* Recursively count nodes in the right subtree */
	int right_count = count_nodes(current_node->right);

	/* Return the total count, which includes the current node */
	return (1 + left_count + right_count);
}

/**
 * heap_to_sorted_array - Convert a binary heap to a sorted array.
 *
 * This function converts a binary heap to a sorted array by repeatedly
 * extracting the maximum element from the heap and storing it in the array.
 *
 * @heap: A pointer to the root node of the binary heap.
 * @size: A pointer to a variable to store the size of the array.
 * Return: pointer to the sorted array, or NULL if the heap is empty.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int x, nodes, *array = NULL;

	*size = 0;

	/* Check if the heap is empty */
	if (!heap)
		return (NULL);

	/* Count the number of nodes in the heap */
	nodes = count_nodes(heap);

	/* Allocate memory for the array */
	array = malloc(sizeof(*array) * nodes);
	if (!array)
		return (NULL);

	/* Set the size of the array */
	*size = nodes;

	/* Extract elements from the heap and store them in the array */
	for (x = 0; x < nodes; x++)
		array[x] = heap_extract(&heap);

	/* Return the sorted array */
	return (array);
}
