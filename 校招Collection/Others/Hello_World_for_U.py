# https://www.nowcoder.com/practice/c6e414fddd7c401887c350c9cc41f01b

k = list()
def f(a, b):
    if (a - b) % 2 == 0:
        n1 = n3 = (a - b) // 2
        n2 = b
        k.append([n1, n2, n3])
try:
    while 1:

        k = []
        s = raw_input()
        a = len(s) + 2
        m = a // 3

        f(a, m)
        f(a, m - 1)
        f(a, m + 1)
        f(a, m + 2)
        f(a, m - 2)

        for n1, n2, n3 in k:
            if n1 + n2 + n3 == a and n1 == n3 and n1 <= n2 and 3 <= n2 <= a - 2:
                res = [n1, n2, n3]
                break

        result = []
        result.append(s[:n1])
        for i in xrange(n2 - 2):
            result.append(' ' * (n1 - 1) + s[n1 + i])
        result.append(s[-n3:][::-1])
        result = list(zip(*result))
        for i in result:
            print ''.join(i)
except:
    pass