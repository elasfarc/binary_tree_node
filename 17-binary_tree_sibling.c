#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node.
 *	If node is NULL or the parent is NULL, return NULL
 *	If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent_left, *parent_right;
	int is_sibling;

	if (!node || !node->parent)
		return (NULL);

	parent_left = node->parent->left;
	parent_right = node->parent->right;
	is_sibling = parent_left && parent_right;

	return (
		is_sibling
		? parent_left->n == node->n
			? parent_right
			: parent_left
		: NULL
	);

}
