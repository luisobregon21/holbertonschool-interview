#!/usr/bin/python3
"""Module rain."""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    :walls (list): contains non-negative integers
    Returns:
        total amount of rainwater retained or 0
    """
    n = len(walls)
    total_water = 0
    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])
        total_water = total_water + (min(left, right) - walls[i])
    return total_water
