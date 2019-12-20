# https://www.nowcoder.com/practice/4462b8519a574b52b5a92e8ea891926a

try:
    while 1:
        a, a_reverse = list(), list()
        b = [''] * 10
        for i in xrange(10):
            s = raw_input()
            a.append(s)
            a_reverse.append(s[::-1])
            for j in xrange(10):
                b[j] += s[j]
        b_reverse = [x[::-1] for x in b]
        L = a + a_reverse + b + b_reverse
        L = list(set(L))
        string = '.'.join(L)

        for j in xrange(input()):
            query = raw_input()
            if query in string:
                print 'Yes'
            else:
                print 'No'
except:
    pass