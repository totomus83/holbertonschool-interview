#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the tree
 *
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * binary_tree_node_at_index - finds node by index (level order)
 * @root: pointer to root
 * @index: index
 *
 * Return: pointer to node
 */
binary_tree_t *binary_tree_node_at_index(binary_tree_t *root, int index)
{
	int path[64], i = 0;
	binary_tree_t *current = root;

	while (index > 1)
	{
		path[i++] = index % 2;
		index /= 2;
	}

	while (i--)
	{
		if (path[i] == 0)
			current = current->left;
		else
			current = current->right;
	}

	return (current);
}

/**
 * heapify_up - moves node up to maintain heap property
 * @node: pointer to node
 *
 * Return: pointer to final position
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - inserts value into a max binary heap
 * @root: double pointer to root
 * @value: value to insert
 *
 * Return: pointer to inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	size = binary_tree_size(*root) + 1;
	parent = binary_tree_node_at_index(*root, size / 2);

	new_node->parent = parent;
	if (size % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}