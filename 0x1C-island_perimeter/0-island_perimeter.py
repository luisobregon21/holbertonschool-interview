#!/usr/bin/python3
''' island perimeter '''


def island_perimeter(grid):
    '''
    returns the perimeter of the island described in grid
    :grid: list of integers. grid is rectangular
        0: represents water
        1: represents land
        each cell is square, with a side length of 1
        cells are connecteed horizontally/vertically
    '''
    perimeter = 0

    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            # if the cell is land, add to the perimeter
            if grid[i][j] == 1:
                perimeter += 4
                # check the adjacent cells and subtract
                #from the perimeter if they are also land
                if i > 0 and grid[i-1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:
                    perimeter -= 2
    return perimeter
