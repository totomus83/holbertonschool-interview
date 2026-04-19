#!/usr/bin/python3
"""
UTF-8 Validation module
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding

    param data: List of integers
    return: True if valid UTF-8, False otherwise
    """
    num_bytes = 0

    for num in data:
        # Keep only 8 least significant bits
        num = num & 0xFF

        if num_bytes == 0:
            # Count leading 1s
            mask = 0b10000000
            while mask & num:
                num_bytes += 1
                mask >>= 1

            # 1-byte character
            if num_bytes == 0:
                continue

            # Invalid cases
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            # Check continuation byte: must start with 10
            if not (num & 0b10000000 and not (num & 0b01000000)):
                return False

        num_bytes -= 1

    return num_bytes == 0
