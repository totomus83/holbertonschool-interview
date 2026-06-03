#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the array being searched
 * @array: Pointer to the first element
 * @left: Left index
 * @right: Right index
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_recursive - Recursive binary search helper
 * @array: Pointer to array
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 *
 * Return: Index of first occurrence or -1
 */
int binary_recursive(int *array, int left, int right, int value)
{
	int mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

    if (left == right)
    {
        print_array(array, left, right);

        if (array[left] == value)
            return (left);
        return (-1);
    }

print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] >= value)
		return (binary_recursive(array, left, mid, value));
	else
		return (binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: Pointer to first element
 * @size: Number of elements
 * @value: Value to search
 *
 * Return: Index of first occurrence or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}