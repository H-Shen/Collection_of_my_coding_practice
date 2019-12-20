# https://www.nowcoder.com/practice/fda725b4d9a14010bb145272cababef1

try:
    while 1:
        a = input()
        if a % 2 != 0:
            print 0, 0
        else:
            result = []
            a /= 2
            for x in xrange(a + 1):
                if (a - x) % 2 == 0:
                    result.append(x + (a - x) / 2)
            print min(result), max(result)
except:
    pass