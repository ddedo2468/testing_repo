#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height of the binary tree OR 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	if (left_h > right_h)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (left_h);
		return (left_h + 1);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (right_h);
		return (right_h + 1);
	}
}
