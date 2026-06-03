#include <stdio.h>
#include <stddef.h>

/* Helper function to print array */
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

/* Recursive binary search */
int binary_recursive(int *array, int left, int right, int value)
{
    int mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        /* Check if it's the first occurrence */
        if (mid == left || array[mid - 1] != value)
            return (mid);
        return (binary_recursive(array, left, mid, value));
    }

    if (array[mid] < value)
        return (binary_recursive(array, mid + 1, right, value));

    return (binary_recursive(array, left, mid - 1, value));
}

/* Main function */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return (binary_recursive(array, 0, size - 1, value));
}