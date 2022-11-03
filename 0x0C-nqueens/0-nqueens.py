#!/usr/bin/python3
'''
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard.
Solution for the N queens problem.
'''


import sys


def place_queen(queen, column, prev_solver):
    placement_queen = []
    for array in prev_solver:
        for idx in range(column):
            if is_safe(queen, idx, array):
                placement_queen.append(array + [idx])
    return placement_queen


def is_safe(queen, idx, array):
    if idx in array:
        return (False)
    else:
        return all(abs(array[column] - idx) != queen - column
                   for column in range(queen))


if __name__ == '__main__':
    args = sys.argv

    if len(args) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(args[1])
    except Exception as e:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    placement = [[]]
    for queen in range(N):
        placement = place_queen(queen, N, placement)

    for array in placement:
        ans = []
        for q, x in enumerate(array):
            ans.append([q, x])
        print(ans)
