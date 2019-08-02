# -*- coding: utf-8 -*-

# Get maximum and minimum concurrectly by taking O(3 * floor(n / 2)) steps
# where n is the length of the array

def minmax(L):
    n = len(L)
    # Case 1: n == 0
    if n == 0:
        raise Exception("L is empty!")
    # Case 2: n == 1
    elif n == 1:
        minVal, maxVal = L[0], L[0]
    # Case 3: n >= 2 and n is even
    elif (n & 1) == 0:
        if L[0] < L[1]:
            minVal, maxVal = L[0], L[1]
        else:
            minVal, maxVal = L[1], L[0]
        for i in range(2, n - 1):
            if L[i] > L[i + 1]:
                if L[i] > maxVal:
                    maxVal = L[i]
                if L[i + 1] < minVal:
                    minVal = L[i + 1]
            else:
                if L[i + 1] > maxVal:
                    maxVal = L[i + 1]
                if L[i] < minVal:
                    minVal = L[i]
    # Case 4: n >= 2 and n is odd
    else:
        minVal, maxVal = L[0], L[0]
        for i in range(1, n - 1):
            if L[i] > L[i + 1]:
                if L[i] > maxVal:
                    maxVal = L[i]
                if L[i + 1] < minVal:
                    minVal = L[i + 1]
            else:
                if L[i + 1] > maxVal:
                    maxVal = L[i + 1]
                if L[i] < minVal:
                    minVal = L[i]
    res = [minVal, maxVal]
    return res

A = [1,2,3,4,1]
print(minmax(A))
A = [1,2]
print(minmax(A))
A = [1,1]
print(minmax(A))
A = [0]
print(minmax(A))
A = list()
try:
    A = list()
    print(minmax(A))
except Exception as ex:
    pass