#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

/* Structs */
/* Main Structs */

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;


/* functions */
/* Main functions */

/* Binary tree print functions */
void binary_tree_print(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 0. New node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/*===========================================================================*/

/* Task 1. Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/*===========================================================================*/

/* Task 2. Insert right */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/*===========================================================================*/

/* Task 3. Delete */
void binary_tree_delete(binary_tree_t *tree);
/*===========================================================================*/

/* Task 4. Is leaf */
int binary_tree_is_leaf(const binary_tree_t *node);
/*===========================================================================*/

/* Task 5. Is root */
int binary_tree_is_root(const binary_tree_t *node);
/*===========================================================================*/

/* Task 6. Pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/*===========================================================================*/

/* Task 7. In-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/*===========================================================================*/

/* Task 8. Post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/*===========================================================================*/

/* Task 9. Height */
size_t calculate_binary_tree_height(const binary_tree_t *root);
size_t binary_tree_height(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 10. Depth */
size_t binary_tree_depth(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 11. Size */
size_t binary_tree_size(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 12. Leaves */
size_t binary_tree_leaves(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 13. Nodes */
size_t binary_tree_nodes(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 14. Balance factor */
/* size_t calculate_binary_tree_height(const binary_tree_t *root); */
/* size_t binary_tree_height(const binary_tree_t *tree); */
int binary_tree_balance(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 15. Is full */
int is_binary_tree_full(const binary_tree_t *root);
int binary_tree_is_full(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 16. Is perfect */
/* int binary_tree_balance(const binary_tree_t *tree); */
/* size_t calculate_binary_tree_height(const binary_tree_t *root); */
int calculate_tree_balance(const binary_tree_t *root);
int binary_tree_is_perfect(const binary_tree_t *tree);
/*===========================================================================*/

/* Task 17. Sibling */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/*===========================================================================*/

/* Task 18. Uncle */
/* binary_tree_t *binary_tree_sibling(binary_tree_t *node); */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
/*===========================================================================*/
/*/////////////////////// ADVANCED TASKS /////////////////////*/

/* Task (100)19. Lowest common ancestor */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
																const binary_tree_t *second);
/*===========================================================================*/

/* Task (101)20. Level-order traversal */
/*size_t calculate_binary_tree_height(const binary_tree_t *root);*/
/*size_t binary_tree_height(const binary_tree_t *tree);*/
void traverse_levelorder_recursive(const binary_tree_t *root,
								   void (*func)(int), size_t level);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
/*===========================================================================*/

/* Task (102)21. Is complete */
/* size_t binary_tree_size(const binary_tree_t *tree); */
int is_complete_recursive(const binary_tree_t *tree,
									size_t index, size_t size);
int binary_tree_is_complete(const binary_tree_t *tree);
/*===========================================================================*/

/* Task (103)22. Rotate left */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
/*===========================================================================*/

/* Task (104)23. Rotate right */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
/*===========================================================================*/

/* Task (110)24. Is BST */
int IsBinarySearch_tree_recursive(const binary_tree_t *root, int min, int max);
int binary_tree_is_bst(const binary_tree_t *tree);
/*===========================================================================*/

/* Task (111)25. BST - Insert */
bst_t *bst_insert_recursive(bst_t *root, int value);
bst_t *bst_insert(bst_t **tree, int value);
/*===========================================================================*/

/* Task (112) 26. BST - Array to BST */
bst_t *array_to_bst(int *array, size_t size);
/*===========================================================================*/

/* Task (113) 27. BST - Search */
bst_t *bst_search(const bst_t *tree, int value);
/*===========================================================================*/

/* Task (114) 28. BST - Remove */
int find_inorder_successor(bst_t *node);
int replace_with_inorder_successor(bst_t *root);
int remove_node(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);
/*===========================================================================*/

/* Task (115) 29. Big O #BST */
/*===========================================================================*/

/* Task (120) 30. Is AVL */
int check_binary_search_tree(const binary_tree_t *root,
							 int minValue, int maxValue);
/* size_t calculate_binary_tree_height(const binary_tree_t *root);*/
/* int binary_tree_balance(const binary_tree_t *tree);*/
/* int calculate_tree_balance(const binary_tree_t *tree);*/
int binary_tree_is_avl(const binary_tree_t *tree);
/*===========================================================================*/

/* Task (121) 31. AVL - Insert */
avl_t *insert_avl_node(avl_t **root, avl_t *parent,
												avl_t **new_node, int value);
avl_t *avl_insert(avl_t **tree, int value);
/*===========================================================================*/

/* Task (122) 32. AVL - Array to AVL */
avl_t *array_to_avl(int *array, size_t size);
/*===========================================================================*/

/* Task (123) 33. AVL - Remove */
void balance_avl_tree(avl_t **root);
/* int find_inorder_successor(bst_t *node); */
/* int remove_node(bst_t *root); */
/* bst_t *bst_remove(bst_t *root, int value); */
avl_t *avl_remove(avl_t *root, int value);
/*===========================================================================*/

/* Task (124) 34. AVL - From sorted array */
avl_t *create_balanced_avl(avl_t *parent, int *array, int start, int end);
avl_t *sorted_array_to_avl(int *array, size_t size);
/*===========================================================================*/

/* Task (125) 35. Big O #AVL Tree */
/*===========================================================================*/

/* Task (130) 36. Is Binary heap */
int binary_tree_is_heap(const binary_tree_t *tree);
/*===========================================================================*/

/*===========================================================================*/

/*===========================================================================*/

/*===========================================================================*/

/*===========================================================================*/

/*===========================================================================*/

/*===========================================================================*/






#endif /* BINARY_TREES_H */
