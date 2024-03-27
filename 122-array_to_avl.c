#include "binary_trees.h"
/**
 * array_to_avl - Creates an AVL tree from an array of integers.
 *
 * This function constructs an AVL tree from the elements of specified array.
 * It iterates through the array, inserting each unique element into AVL tree.
 * If the array is empty or contains only duplicates, function returns NULL.
 *
 * @array: A pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the constructed AVL tree,
 * or NULL if the array is empty or contains only duplicates.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t x, y;
	avl_t *root;

	root = NULL;

	/* If the array is empty, return NULL */
	if (size == 0)
	{
		return (NULL);
	}

	/* Iterate through the array */
	for (x = 0; x < size; x++)
	{
		/* Check for duplicate elements */
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}

		/* If the current element is unique, insert it into the AVL tree */
		if (y == x)
		{
			/* Attempt to insert the element into the AVL tree */
			if (avl_insert(&root, array[x]) == NULL)
			{
				return (NULL); /* Return NULL if insertion fails */
			}
		}
	}

	return (root);
}
