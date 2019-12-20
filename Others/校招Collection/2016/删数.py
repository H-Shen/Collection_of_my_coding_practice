# https://www.nowcoder.com/practice/f9533a71aada4f35867008be22be5b6e

def Monkey(n, M):
    if n == 0 or M == 1:
        return 0
    L = map(list,list(enumerate([True] * n )))
    counter = 0
    currentLength = len(L)
    while [L[i][1] for i in xrange(currentLength)].count(True) > 1:
        for i in xrange(currentLength):
            if L[i][1] == True:
                counter += 1
            if counter % M == 0 and L[i][1] == True:
                L[i][1] = False
        currentLength = len(L)
    return filter(lambda x:x[1] == True, L)[0][0]
try:
    while 1:
        n = input()
        print Monkey(n, 3)
except:
    pass
