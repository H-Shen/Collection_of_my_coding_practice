# https://www.nowcoder.com/practice/776d401bf86d446fa783f0bef7d3c096

try:
    while 1:
        print sum(map(lambda y:y ** 2,filter(lambda x:not '7' in str(x) and x % 7 != 0,[i for i in xrange(1, input() + 1)])))
except:
    pass