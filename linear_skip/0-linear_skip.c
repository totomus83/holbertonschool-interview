#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: pointer to head of skip list
 * @value: value to search for
 *
 * Return: pointer to first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *prev, *curr, *temp;

    if (!list)
        return (NULL);

    prev = list;
    curr = list->express;

    /* Traverse express lane */
    while (curr)
    {
        printf("Value checked at index [%lu] = [%d]\n",
               curr->index, curr->n);

        if (curr->n >= value)
            break;

        prev = curr;
        curr = curr->express;
    }

    /* If we ran out of express lane, go to last node */
    if (!curr)
    {
        temp = prev;
        while (temp->next)
            temp = temp->next;
        curr = temp;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, curr->index);

    /* Linear search within the block */
    temp = prev;
    while (temp && temp->index <= curr->index)
    {
        printf("Value checked at index [%lu] = [%d]\n",
               temp->index, temp->n);

        if (temp->n == value)
            return (temp);

        temp = temp->next;
    }

    return (NULL);
}