#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent:  pointer to the node to insert the left-child in
 * @value:  value to store in the new node
 *
 * If parent already has a left-child, the new node must take its place, and
 * the old left-child must be set as the left-child of the new node.
 *
 * Return: A pointer to the created node,
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	if (!parent)
		return (NULL);
	binary_tree_t *node = binary_tree_node(parent, value);

	if (!node)
		return (NULL);

	binary_tree_t *old_left = parent->left;

	parent->left = node;
	if (old_left)
	{
		old_left->parent = node;
		node->left = old_left;
	}
	return (node);
}
