import numpy

def arrays(k):
    k.reverse()
    return numpy.array(k,float)

arr = input().strip().split(' ')
result = arrays(arr)
print(result)