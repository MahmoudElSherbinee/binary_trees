#include "binary_trees.h"

/**
* find_lowest_common_ancestor - Recursively finds the lowest
* common ancestor of two nodes in a binary tree.
* This function recursively searches for the lowest common ancestor (LCA)
* of two nodes in a binary tree.
* If one of the nodes is a descendant of the other,
* the descendant node is considered its own ancestor.
*
* @root: A pointer to the root node of the binary tree.
* @first: A pointer to the first node.
* @second: A pointer to the second node.
*
* Return: A pointer to the lowest common ancestor node,
* or NULL if one of the nodes is not found or if the tree is empty.
*/
binary_tree_t *find_lowest_common_ancestor(binary_tree_t *root,
											const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *left_lca = NULL, *right_lca = NULL;

	if (root == NULL || first == NULL || second == NULL)
		return (NULL);

	if (root == first || root == second)
		return (root);

	left_lca = find_lowest_common_ancestor(root->left, first, second);
	right_lca = find_lowest_common_ancestor(root->right, first, second);

	if (left_lca && right_lca)
		return (root);

	if (left_lca != NULL)
		return (left_lca);

	return (right_lca);
}

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
*		or NULL if either of the given nodes is NULL or
*				they are not part of the same tree.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *root = NULL;

	/* If either of the given nodes is NULL, they cannot have a common ancestor */
	if (!first || !second)
		return (NULL);

	/* Find the root node of the binary tree */
	root = (binary_tree_t *)first;
	while (root->parent != NULL)
		root = root->parent;

	/* Perform lowest common ancestor detection */
	return (find_lowest_common_ancestor(root, first, second));
}
