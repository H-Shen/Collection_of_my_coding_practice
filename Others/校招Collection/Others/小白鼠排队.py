# https://www.nowcoder.com/practice/27fbaa6c7b2e419bbf4de8ba60cf372b

try:
    while 1:
        a = list()
        for i in xrange(input()):
            b = raw_input().split()
            b[0] = int(b[0])
            a.append(b)
        a.sort(key=lambda x:x[0], reverse=True)
        for j, k in a:
            print k
except:
    pass