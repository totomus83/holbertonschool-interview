#ifndef SEARCH_H
#define SEARCH_H

#include <stddef.h>

/**
 * struct skiplist_s - Skip list node
 * @n: integer value
 * @index: index of the node
 * @next: pointer to next node
 * @express: pointer to express lane node
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/* Required function prototypes */
skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *create_skiplist(int *array, size_t size);
void free_skiplist(skiplist_t *list);

#endif /* SEARCH_H */