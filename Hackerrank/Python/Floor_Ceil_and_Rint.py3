import numpy
numpy.set_printoptions(sign=' ')
s = numpy.array(list(map(float,input().split())))
print(numpy.floor(s))
print(numpy.ceil(s))
print(numpy.rint(s))
