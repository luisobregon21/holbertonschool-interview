#!/usr/bin/python3
''' Minimum Operations '''


def minOperations(n):
    '''
    method calculates the fewest number of operations
    needed to result in exactly n H characters in the file.
    '''
    if n < 2:
        return 0

    count = 1
    li = list()
    value = n
    while value != 1:
        count += 1
        if value % count == 0:
            while value % count == 0 and value != 1:
                value = value / count
                li.append(count)

    return sum(li)
