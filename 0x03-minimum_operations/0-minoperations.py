#!/usr/bin/env python3
''' Minimum Operations '''


def minOperations(n):
    '''
    method calculates the fewest number of operations
    needed to result in exactly n H characters in the file.
    '''
    if n < 2:
        return 0

    num = 1
    tmp = 0
    count = 0
    while num < n:
        count += 1  # copy
        tmp = num
        if num+tmp >= n:
            break
        num += tmp  # paste
        count += 1
        num += tmp  # paste
        count += 1
    return count
