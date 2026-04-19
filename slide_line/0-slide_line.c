#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers
 * @size: number of elements
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j;

    if (!line || size == 0 ||
        (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
    {
        /* Step 1: shift left (remove zeros) */
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }

        /* Step 2: merge */
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] != 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
                i++; /* skip next */
            }
        }

        /* Step 3: shift again */
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
    }
    else /* SLIDE_RIGHT */
    {
        /* Step 1: shift right */
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] == 0)
            {
                for (j = i; j > 0; j--)
                {
                    if (line[j - 1] != 0)
                    {
                        line[i] = line[j - 1];
                        line[j - 1] = 0;
                        break;
                    }
                }
            }
        }

    /* Step 2: merge */
    for (i = size - 1; i > 0; i--)
    {
        if (line[i] != 0 && line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
            i--;
        }
    }

    /* Step 3: shift again */
    for (i = size - 1; i > 0; i--)
    {
        if (line[i] == 0)
        {
            for (j = i; j > 0; j--)
            {
                if (line[j - 1] != 0)
                {
                    line[i] = line[j - 1];
                    line[j - 1] = 0;
                    break;
                }
            }
        }
    }
}

        /* Step 2: merge */
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] != 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
                i--; /* skip next */
            }
        }

        /* Step 3: shift again */
        for (i = size; i-- > 0;)
        {
            if (line[i] == 0)
            {
                for (j = i; j-- > 0;)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
    }

    return (1);
}