# https://www.nowcoder.com/practice/2364ff2463984f09904170cf6f67f69a

try:
    while 1:
        a = list()
        n = input()
        if n == 0:
            break
        for _ in xrange(n):
            a.append(input())
        a.sort()
        if n % 2 == 0:
            mid = n / 2
            print int((a[mid - 1] + a[mid]) / 2)
        else:
            print a[(n + 1) / 2 - 1]
except:
    pass