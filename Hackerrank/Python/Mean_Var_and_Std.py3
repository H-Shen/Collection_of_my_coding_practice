import numpy

numpy.set_printoptions(legacy='1.13')

result = list()
for _ in range(list(map(int,input().split()))[0]):
    result.append(list(map(int,input().split())))
my_array = numpy.array(result)

print(numpy.mean(my_array, axis = 1))
print(numpy.var(my_array, axis = 0))
print(numpy.std(my_array, axis = None))

