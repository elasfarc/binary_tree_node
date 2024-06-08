#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another
 * node.
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node
 *
 * If parent already has a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 *
 * Return: A pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *old_right;

	if (!parent)
		return (NULL);
	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	old_right = parent->right;
	parent->right = node;

	if (old_right)
	{
		old_right->parent = node;
		node->right = old_right;
	}

	return (node);

}
