def count(k, num):
    result = []
    while num % k == 0:
        result.append(k)
        num //= k
        k += 1
    return result
 
n = input()
k = []
for i in xrange(2, int(n ** 0.5) + 1):
    if n % i == 0:
        k.append(count(i, n))
if len(k) == 0:
    print 1
    print n
else:
    ans = max(k, key=len)
    length = len(ans)
    print len(ans)
    print '*'.join(map(str, ans))