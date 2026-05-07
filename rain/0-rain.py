#!/usr/bin/python3
"""
Rain water trapping problem
"""


def rain(walls):
    """
    Calculate total trapped rainwater
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)

    left_max = [0] * n
    right_max = [0] * n

    # compute left max
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # compute right max
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # compute water
    total = 0
    for i in range(n):
        water = min(left_max[i], right_max[i]) - walls[i]
        if water > 0:
            total += water

    return total
