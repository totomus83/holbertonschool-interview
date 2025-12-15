#!/usr/bin/python3
"""
lockboxes module
determines if all boxes can be unlocked.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    args provided in 0-main
    returns a bool depending on if all the boxes are reachable"""
    if not isinstance(boxes, list):
        return False

    n = len(boxes)
    unlocked = set([0])   # Box 0 is unlocked
    keys = set(boxes[0])  # Keys available from box 0

    while keys:
        key = keys.pop()
        if key < n and key not in unlocked:
            unlocked.add(key)
            keys.update(boxes[key])

    return len(unlocked) == n
