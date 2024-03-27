#include "binary_trees.h"

/**
 * array_to_heap - Converts an array of integers into a binary heap.
 *
 * This function takes an array of integers and converts it into a binary heap.
 * It iterates through the array and inserts each element
 * into the heap using the heap_insert function.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: A pointer to the root of the binary heap.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}

	return (tree);
}
