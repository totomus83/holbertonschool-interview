#!/usr/bin/python3
"""
Minimum Operations module
"""


def minOperations(n):
    """
    Calculates the minimum number of operations needed to get n 'H's
    using only Copy All and Paste operations.

    Args:
        n (int): Target number of H characters.

    Returns:
        int: Minimum number of operations to get exactly n H characters.
             Returns 0 if impossible (n < 1).
    """
    if n < 2:
        return 0

    res = 0
    i = 2
    while i <= n:
        while n % i == 0:
            res += i
            n //= i
        i += 1
    return res
