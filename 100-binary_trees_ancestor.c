#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 *	If no common ancestor was found, returns NULL
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second
)
{
	binary_tree_t *first_parent =  first->parent, *second_parent = second->parent;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return (first_parent->left);
	/**  instead of simply 'first' bc of confilct of type (const)*/


	while (first_parent && second_parent)
	{
		if (first_parent == second || first_parent == second->parent)
			return (first_parent);
		if (second_parent == first || second_parent == first->parent)
			return (second_parent);
		first_parent = first_parent->parent;
		second_parent = second_parent->parent;
	}



	return (NULL);
}
