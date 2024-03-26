#include "binary_trees.h"

/**
* find_lowest_common_ancestor - Recursively finds the lowest
* common ancestor of two nodes in a binary tree.
* This function recursively searches for the lowest common ancestor (LCA)
* of two nodes in a binary tree.
* If one of the nodes is a descendant of the other,
* the descendant node is considered its own ancestor.
*
* @first: A pointer to the first node.
* @second: A pointer to the second node.
*
* Return: A pointer to the lowest common ancestor node,
* or NULL if one of the nodes is not found or if the tree is empty.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *p, *q;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	p = first->parent;
	q = second->parent;
	if (p == NULL || first == q || (!p->parent && q))
	{
		return (binary_trees_ancestor(first, q));
	}
	else if (q == NULL || p == second || (!q->parent && p))
	{
		return (binary_trees_ancestor(p, second));
	}
	return (binary_trees_ancestor(p, q));
}
