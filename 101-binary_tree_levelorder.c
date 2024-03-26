#include "binary_trees.h"

/**
 * traverse_levelorder_recursive - Recursively traverses
 * a binary tree in level-order.
 *
 * This function recursively traverses the binary tree
 * in level-order and applies a function to each node.
 * Level-order traversal visits nodes at each level from left to right.
 *
 * @root: A pointer to the root node of the binary tree.
 * @func: A pointer to the function to apply to each node.
 * @level: The current level being traversed.
 */
void traverse_levelorder_recursive(const binary_tree_t *root,
								   void (*func)(int), size_t level)
{
	if (root == NULL)
		return;

	if (level == 0)
		func(root->n);

	traverse_levelorder_recursive(root->left, func, level - 1);
	traverse_levelorder_recursive(root->right, func, level - 1);
}
/**
 * calculate_binary_tree_height - Recursively calculates
 * the height of a binary tree.
 * This function recursively calculates the height
 * of the binary tree rooted at the given node.
 * The height of a binary tree is defined as the maximum number
 * of edges between the root node and a leaf node.
 *
 * @root: A pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree rooted at the given node.
 */
size_t calculate_binary_tree_height(const binary_tree_t *root)
{
	size_t height_right, height_left;

	/* Base case: If the tree is empty, its height is 0 */
	if (!root)
		return (0);

	/* Recursively calculate the height of the left subtree */
	height_left = calculate_binary_tree_height(root->left);

	/* Recursively calculate the height of the right subtree */
	height_right = calculate_binary_tree_height(root->right);

	/* Return the height of the taller subtree */
	/* plus 1 (to account for the root node) */
	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 *
 * This function calculates the height of the binary tree
 * rooted at the given node.
 * The height of a binary tree is defined as the maximum number
 * of edges between the root node and a leaf node.
 *
 * @tree: A pointer to the root node of the binary tree.
 * Return: The height of the binary tree rooted at the given node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* Calculate the height using the recursive function */
	/* and subtract 1 to exclude the root node */
	return (calculate_binary_tree_height(tree) - 1);
}

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree.
 *
 * This function performs a level-order traversal
 * on the binary tree rooted at the given node.
 * Level-order traversal visits all nodes at each level
 * from left to right before moving to the next level.
 *
 * @tree: A pointer to the root node of the binary tree.
 * @func: A pointer to the function that will be called
 * for each visited node, with the value of the node as an argument.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level = 0;

	/* If the tree or the function pointer is NULL, return */
	if (!tree || !func)
		return;

	/* Retrieve the height of the binary tree */
	height = binary_tree_height(tree);

	/* Traverse each level of the binary tree in level-order */
	while (level <= height)
	{
		/* Call the helper function for the current level */
		traverse_levelorder_recursive(tree, func, level);
		level++;								   /* Move to the next level */
	}
}
