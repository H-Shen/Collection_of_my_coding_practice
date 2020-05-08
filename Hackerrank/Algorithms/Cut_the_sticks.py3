#!/bin/python3

import sys

n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]

while len(arr) != arr.count(0):
    print(len(arr) - arr.count(0))
    tmp = list(set(arr))
    if 0 in tmp:
        tmp.remove(0)
    cut = min(tmp)
    for i in range(len(arr)):
        arr[i] -= cut
        if arr[i] <= 0:
            arr[i] = 0
