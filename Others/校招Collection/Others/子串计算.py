# https://www.nowcoder.com/practice/bcad754c91a54994be31a239996e7c11

try:
    while 1:
        table = {}
        s = raw_input()
        L = len(s)
        for i in xrange(L):
            for j in xrange(i + 1, L + 1):
                current = s[i:j]
                if not current in table:
                    table[current] = 1
                else:
                    table[current] += 1
        result = sorted(filter(lambda x:x[1] != 1, table.items()),key=lambda x:x[0])
        for u, v in result:
            print u, v
except:
    pass