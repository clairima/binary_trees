#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree);
	int level;

	if (tree == NULL || func == NULL)
		return;

	for (level = 1; level <= height + 1; level++)
	{
		level_order_helper(tree, func, level);
	}
}

/**
 * level_order_helper - Recursive helper function for level-order traversal
 * @tree: Pointer to the current node being processed
 * @func: Pointer to a function to call for each node's value
 * @level: The current level being visited
 */
void level_order_helper(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		level_order_helper(tree->left, func, level - 1);
		level_order_helper(tree->right, func, level - 1);
	}
}
