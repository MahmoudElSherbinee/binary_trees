#include "binary_trees.h"
binary_tree_t *recurse_for_ancestor(binary_tree_t *root,
	const binary_tree_t *first, const binary_tree_t *second);
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
binary_tree_t *recurse_for_ancestor(binary_tree_t *root,
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *leftLCA = NULL, *rightLCA = NULL;

	if (root == NULL || first == NULL || second == NULL)
		return (NULL);

	if (root == first || root == second)
		return (root);

	leftLCA = recurse_for_ancestor(root->left, first, second);
	rightLCA = recurse_for_ancestor(root->right, first, second);

	if (leftLCA && rightLCA)
		return (root);

	if (leftLCA != NULL)
		return (leftLCA);
	return (rightLCA);
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

	if (!first || !second)
		return (NULL);

	/* find root node */
	root = (binary_tree_t *)first;
	while (root->parent != NULL)
		root = root->parent;

	/* perform lowest common anscestor detection */
	return (recurse_for_ancestor(root, first, second));
}
