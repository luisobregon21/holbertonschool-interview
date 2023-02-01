#!/usr/bin/env python3
''' rotate_2d_matrix '''


def rotate_2d_matrix(matrix):
    '''
    rotates a matrix 90 degrees clockwise
    :matrix: matrix to be rotated
    '''
    num = len(matrix)
    for i in range(num // 2):
        for j in range(i, num - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[num - j - 1][i]
            matrix[num - j - 1][i] = matrix[num - i - 1][num - j - 1]
            matrix[num - i - 1][num - j - 1] = matrix[j][num - i - 1]
            matrix[j][num - i - 1] = temp
