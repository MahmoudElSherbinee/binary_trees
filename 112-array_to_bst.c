#include "binary_trees.h"

/**
 * array_to_bst - Constructs a binary search tree
 * (BST) from an array of integers.
 * This function constructs a binary search tree
 * (BST) from the given array of integers.
 * It iterates through the array and inserts each element
 * into the BST using the bst_insert function.
 *
 * @array: A pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the constructed BST if successful,
 * or NULL if the array is NULL or empty.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;

	/* If the array pointer is NULL or the size is 0, return NULL */
	if (array == NULL || size == 0)
		return (NULL);

	/* Create the root node of the tree */
	tree = bst_insert(&tree, array[i++]);

	/* Iterate through the array, inserting values into the tree */
	while (i < size)
	{
		bst_insert(&tree, array[i]);
		i++;
	}
	return (tree);
}
