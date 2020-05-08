#!/bin/python3

import sys

def superDigit(n, k):
    # Complete this function

    if len(n) == 1:
        return n
    n = str(sum(map(int, list(n))))
    return superDigit(n, k)

if __name__ == "__main__":
    n, k = input().strip().split(' ')
    n, k = [str(n), int(k)]
    n = str(sum(map(int, n)) * k)
    result = superDigit(n, k)
    print(result)
