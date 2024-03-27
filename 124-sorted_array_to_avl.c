#include "binary_trees.h"

/**
 * create_balanced_avl - Creates a balanced AVL tree from a sorted array.
 * This function creates a balanced AVL tree
 * from the elementsof the specified sorted array.
 * It recursively constructs the AVL tree by selecting
 * the middle element of the array as the root node,
 * then recursively creating the left subtree from
 * the elements before the middle element and
 * the right subtree from the elements after the middle element.
 *
 * @parent: A pointer to the parent node of the current subtree.
 * @array: A pointer to the sorted array of integers.
 * @start: The index of the first element of the current subtree in the array.
 * @end: The index of the last element of the current subtree in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL if the array is empty or invalid.
 */
avl_t *create_balanced_avl(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	binary_tree_t *x;
	int middle = 0;

	/* Base case: if start index exceeds end index, return NULL */
	if (start > end)
		return (NULL);

	/* Calculate the index of the middle element */
	middle = (start + end) / 2;

	/* Create a new node using the middle element as the value */
	x = binary_tree_node((binary_tree_t *)parent, array[middle]);
	if (x == NULL)
		return (NULL);

	/* Cast the new node as an AVL node */
	root = (avl_t *)x;

	/* Recursively create the left subtree */
	root->left = create_balanced_avl(root, array, start, middle - 1);

	/* Recursively create the right subtree */
	root->right = create_balanced_avl(root, array, middle + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - Converts a sorted array into a balanced AVL tree.
 *
 * This function converts a sorted array of integers into a balanced AVL tree.
 * It recursively constructs the AVL tree by selecting
 * the middle element of the array as the root node,
 * then recursively creating the left subtree
 * from the elements before the middle element and
 * the right subtree from the elements after the middle element
 * using the `x_sort` function.
 *
 * @array: A pointer to the sorted array of integers.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL if the array is empty or invalid.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	/* Call xiliary function to recursively construct the AVL tree */
	return (create_balanced_avl(NULL, array, 0, ((int)(size)) - 1));
}
