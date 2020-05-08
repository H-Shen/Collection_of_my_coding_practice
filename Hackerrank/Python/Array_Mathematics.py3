# Enter your code here. Read input from STDIN. Print output to STDOUT

import numpy

n, m = list(map(int,input().split()))
A, B = list(), list()

for _ in range(n):
    A.append(list(map(int,input().split())))
for _ in range(n):
    B.append(list(map(int,input().split())))

A = numpy.array(A)
B = numpy.array(B)

print(A + B)
print(A - B)
print(A * B)
print(A // B)
print(A % B)
print(A ** B)

