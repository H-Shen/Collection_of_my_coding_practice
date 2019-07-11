# https://open.kattis.com/problems/anagramcounting
a = [1]
m = 1

for i in range(1, 102):
    m *= i
    a.append(m)
    
try:
    while 1:
        A = dict()
        s = input()
        for i in s:
            if not i in A:
                A[i] = 1
            else:
                A[i] += 1
        res = a[len(s)]
        for i in A:
            res //= a[A[i]]
        print(res)
except:
    pass
