#!/usr/bin/python3
""" island permiter """


def island_perimeter(grid):
    """
    get the perimeter of an island

    - island_perimeter: the island perimeter
    - grid (list): an array that shows the island's informations
    - Return: The island perimeter
    """
    island_perimeter = 0
    row, column = len(grid), len(grid[0])

    for i in range(row):
        for j in range(column):
            if grid[i][j] == 0:
                continue
            island_perimeter += 4
            if i > 0:
                island_perimeter -= grid[i-1][j]
            if j > 0:
                island_perimeter -= grid[i][j-1]
            if i < row-1:
                island_perimeter -= grid[i+1][j]
            if j < column-1:
                island_perimeter -= grid[i][j+1]
    return island_perimeter
