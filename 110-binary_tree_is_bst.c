#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_util - Recursive utility function to check if a tree is a valid BST
 * @node: Current node to check
 * @min: Minimum value constraint for the node
 * @max: Maximum value constraint for the node
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	return (is_bst_util(node->left, min, node->n) &&
		is_bst_util(node->right, node->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is
 * a valid Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
