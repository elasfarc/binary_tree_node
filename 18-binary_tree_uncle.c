#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle.
 *
 * Return: A pointer to the uncle node.
 *	If node is NULL return NULL
 *	If node has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_pa = node && node->parent && node->parent->parent
								? node->parent->parent
								: NULL;

	int is_uncle = grand_pa && grand_pa->left && grand_pa->right;

	return (
		is_uncle
		? grand_pa->left->n  == node->parent->n
			? grand_pa->right
			: grand_pa->left
		: NULL
	);

}
