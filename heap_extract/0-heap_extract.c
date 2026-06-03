#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_size - Returns the total number of nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes, or 0 if tree is NULL
 */
static size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * bfs_get - Returns the node at a given 1-based BFS (level-order) index
 * @root: Pointer to the root of the heap
 * @i: 1-based index (root=1, left child=2i, right child=2i+1)
 *
 * Return: Pointer to the node at index i, or NULL
 */
static heap_t *bfs_get(heap_t *root, size_t i)
{
	heap_t *parent;

	if (!root || i == 0)
		return (NULL);
	if (i == 1)
		return (root);
	if (i == 2)
		return (root->left);
	if (i == 3)
		return (root->right);

	parent = bfs_get(root, i / 2);
	if (!parent)
		return (NULL);
	if (i % 2 == 0)
		return (parent->left);
	return (parent->right);
}

/**
 * sift_down - Restores max-heap property by sifting a node downward
 * @node: Pointer to the node to sift down from
 */
static void sift_down(heap_t *node)
{
	heap_t *largest;
	int tmp;

	if (!node)
		return;

	largest = node;
	if (node->left && node->left->n > largest->n)
		largest = node->left;
	if (node->right && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		tmp = node->n;
		node->n = largest->n;
		largest->n = tmp;
		sift_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = bfs_get(*root, size);

	(*root)->n = last->n;

	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;

	free(last);
	sift_down(*root);

	return (value);
}
