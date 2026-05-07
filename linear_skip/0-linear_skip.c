#include <stdio.h>
#include "search.h"

static skiplist_t *scan_express(skiplist_t *list, int value,
skiplist_t **prev)
{
skiplist_t *curr;

curr = list->express;

while (curr)
{
printf("Value checked at index [%lu] = [%d]\n",
curr->index, curr->n);

if (curr->n >= value)
break;

*prev = curr;
curr = curr->express;
}

return (curr);
}

static skiplist_t *linear_search(skiplist_t *start,
skiplist_t *end, int value)
{
skiplist_t *tmp;

tmp = start;

while (tmp && tmp->index <= end->index)
{
printf("Value checked at index [%lu] = [%d]\n",
tmp->index, tmp->n);

if (tmp->n == value)
return (tmp);

tmp = tmp->next;
}

return (NULL);
}

skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *prev, *curr, *result;

if (!list)
return (NULL);

prev = list;
curr = scan_express(list, value, &prev);

if (!curr)
{
while (prev->next)
prev = prev->next;
curr = prev;
}

printf("Value found between indexes [%lu] and [%lu]\n",
prev->index, curr->index);

result = linear_search(prev, curr, value);

return (result);
}