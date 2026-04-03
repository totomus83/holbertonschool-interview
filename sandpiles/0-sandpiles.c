#include "sandpiles.h"
#include <stdio.h>

/**
 * is_stable - checks if a 3x3 sandpile grid is stable
 * @grid: grid to check
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - perform one toppling round on the grid
 * @grid: grid to topple
 */
void topple(int grid[3][3])
{
    int i;
    int j;
    int temp[3][3] = {0};

    for (i = 0; i < 3; i++)
    {
	    for (j = 0; j < 3; j++)
	    {
		    if (grid[i][j] > 3)
		    {
			    int grains = grid[i][j] / 4;
			    temp[i][j] -= grains * 4;

			    if (i > 0)
			    {
				    temp[i - 1][j] += grains;
			    }
			    if (i < 2)
			    {
				    temp[i + 1][j] += grains;
			    }
			    if (j > 0)
			    {
				    temp[i][j - 1] += grains;
			    }
			    if (j < 2)
			    {
				    temp[i][j + 1] += grains;
			    }
		    }
	    }
    }

	/* apply changes to original grid */
    for (i = 0; i < 3; i++)
	{
        for (j = 0; j < 3; j++)
		{
            grid[i][j] += temp[i][j];
		}
	}
}

/**
 * print_grid - prints a 3x3 grid
 * @grid: grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
    for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles and stabilizes
 * @grid1: first 3x3 grid (will hold result)
 * @grid2: second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* sum grid2 into grid1 */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	/* stabilize */
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}