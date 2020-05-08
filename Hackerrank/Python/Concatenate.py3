import numpy

n, m, p = list(map(int,input().split()))
k = list()
for i in range(m + n):
    s = numpy.array([list(map(int,input().split()))])
    k.append(s)
k = tuple(k)

print(numpy.concatenate(k, axis = 0))
