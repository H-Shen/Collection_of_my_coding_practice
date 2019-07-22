#!/bin/python3

import sys

N = int(input())
arr = list(map(int,input().split()))

if all([x % 2 == 0 for x in arr]):
    print(0)

elif all([x % 2 != 0 for x in arr]):
    if N % 2 == 0:
        print(N)
    else:
        print('NO')

else:
    count = 0

    if arr[0] % 2 != 0 and arr[1] % 2 == 0:
        arr[0] += 1
        arr[1] += 1
        count += 2

    for i in range(1, N):
        if arr[i] % 2 != 0 and arr[i - 1] % 2 != 0:
            arr[i] += 1
            arr[i - 1] += 1
            count += 2
        if arr[i] % 2 != 0 and arr[i - 1] % 2 == 0:
            if i + 1 != N:
                arr[i] += 1
                arr[i + 1] += 1
                count += 2

    if arr[-1] % 2 != 0:
        print('NO')
    else:
        print(count)
