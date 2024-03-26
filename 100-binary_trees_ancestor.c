#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * of two nodes in a binary tree.
 *
 * This function finds the lowest common ancestor (LCA)
 * of the two given nodes in the binary tree.
 * The lowest common ancestor of two nodes in a binary tree
 * is the lowest (i.e., deepest) node that has both nodes as descendants.
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node if found,
 * or NULL if either of the given nodes is NULL or
 * they are not part of the same tree.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
const binary_tree_t *parent1, *parent2;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	parent1 = first->parent;
	parent2 = second->parent;

	/* If one of the nodes is a direct ancestor of the other */
	if (parent1 == NULL || first == parent2 || (!parent1->parent && parent2))
	{
		return (binary_trees_ancestor(first, parent2));
	}
	/* If one of the nodes is not found or has no parent */
	else if (parent2 == NULL || parent1 == second
	|| (!parent2->parent && parent1))
	{
		return (binary_trees_ancestor(parent1, second));
	}
	/* Recursively find the ancestor */
	return (binary_trees_ancestor(parent1, parent2));
}
