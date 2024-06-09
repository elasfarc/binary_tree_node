#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, returns 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_left, is_right;
	int is_children = tree && tree->left && tree->right;
	int is_leaf = tree && !tree->left && !tree->right;



	if (is_children || is_leaf)
	{
		is_left = is_leaf ? 1 : binary_tree_is_full(tree->left);
		is_right = is_leaf ? 1 : binary_tree_is_full(tree->right);
		return (is_left && is_right);
	}

	return (0);
}
