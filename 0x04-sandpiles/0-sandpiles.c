#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
    int i, j;

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
 * add_grids - add grids grid1 and grid2
 * @grid1: individually stable
 * @grid2: individually stable
 */

static void add_grids(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
}
/**
 * topple - Move across the grid to operate a sum3
 * @grid: type int a sandpile 3 x 3
 * @nextpile: type int temporary grid with the sandpile 3 x 3
 */

static void topple(int grid[3][3], int nextpile[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            nextpile[i][j] = 0;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                nextpile[i][j] -= 4;
                if (i + 1 < 3)
                    nextpile[i + 1][j] += 1;
                if (i - 1 >= 0)
                    nextpile[i - 1][j] += 1;
                if (j + 1 < 3)
                    nextpile[i][j + 1] += 1;
                if (j - 1 >= 0)
                    nextpile[i][j - 1] += 1;
            }
        }
    }
}

/**
 * is_sandpile - Checks if the grid contains valid
 * sandpile
 * @grid: a sandpile 3 x 3
 * Return: boolean
 */
static int is_sandpile(int grid[3][3])
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
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: individually stable
 * @grid2: individually stable
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

    int nextpiles[3][3];

    add_grids(grid1, grid2);
    while (is_sandpile(grid1) == 0)
    {
        print_grid(grid1);
        topple(grid1, nextpiles);
        add_grids(grid1, nextpiles);
    }
}
