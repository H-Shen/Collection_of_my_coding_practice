# https://www.nowcoder.com/practice/abdd24fa839c414a9b83aa9c4ecd05cc

def ComplexInput(result):
    x, y = int(result[:result.index('+')]), int(result[result.index('+') + 2:])
    return (x, y, x ** 2 + y ** 2)

try:
    while 1:
        ComplexSet = set()
        for i in xrange(input()):
            command = raw_input().split()
            if command[0] == 'Pop':
                if len(ComplexSet) == 0:
                    print 'empty'
                else:
                    max_length = max(ComplexSet, key=lambda x:x[2])[2]
                    result = min(filter(lambda x:x[2] == max_length, ComplexSet), key=lambda x:x[1])
                    print str(result[0]) + '+i' + str(result[1])
                    ComplexSet.remove(result)
                    print 'SIZE =', len(ComplexSet)
            else:
                ComplexSet.add(ComplexInput(command[1]))
                print 'SIZE =', len(ComplexSet)
except:
    pass