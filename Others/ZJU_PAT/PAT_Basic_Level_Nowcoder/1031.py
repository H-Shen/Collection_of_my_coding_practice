from collections import OrderedDict

try:
    while 1:
        table = OrderedDict()
        for i in xrange(10):
            table[str(i)] = 0

        a = raw_input()
        for i in a:
            table[i] += 1
        a = table.items()

        Max = max(a, key=lambda x: x[1])[1]

        s = []
        for j in xrange(10):
            s.append([str(j)] + a[j][1] * ['*'] + (Max - a[j][1]) * [' '])

        s = zip(*s)[::-1]

        for m in s:
            print ''.join(m)

except:
    pass