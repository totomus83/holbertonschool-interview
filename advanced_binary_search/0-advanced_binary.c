#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the elements of an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
static void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursive helper for advanced binary search
 * @array: Pointer to the first element of the subarray to search in
 * @size: Number of elements in the subarray
 * @value: Value to search for
 * @offset: Index offset of the subarray within the original array
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
static int advanced_binary_recursive(int *array, size_t size, int value,
				     size_t offset)
{
	size_t mid;

	if (!array || size == 0)
		return (-1);

	print_array(array, size);

	mid = (size - 1) / 2;

	if (array[mid] == value && (mid == 0 || array[mid - 1] != value))
		return ((int)(offset + mid));

	if (value <= array[mid])
		return (advanced_binary_recursive(array, mid + 1, value, offset));

	return (advanced_binary_recursive(array + mid + 1, size - mid - 1,
					  value, offset + mid + 1));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   and returns the index of the first occurrence
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, size, value, 0));
}