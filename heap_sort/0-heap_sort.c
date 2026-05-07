#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - restores heap property
 * @array: array
 * @size: size of heap
 * @root: root index
 * @end: last index
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child;
	size_t swap_idx;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx]);
		print_array(array, size);

		root = swap_idx;
	}
}

/**
 * heap_sort - sorts an array using heap sort (sift-down)
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	size_t end;

	if (!array || size < 2)
		return;

	/* Build max heap */
	i = size / 2;
	while (i > 0)
	{
		i--;
		sift_down(array, size, i, size - 1);
	}

	/* Extract elements */
	end = size - 1;
	while (end > 0)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
