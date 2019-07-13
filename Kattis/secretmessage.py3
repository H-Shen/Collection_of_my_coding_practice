# https://open.kattis.com/problems/secretmessage

n = int(input())

for i in range(n):
    s = input()
    l = len(s)
    
    a = pow(l, 0.5)
    if a % 1 == 0:
        k = int(a)
    else:
        k = int(a) + 1
    s += (k * k - l) * '*'
        
    A = [['' for i in range(k)] for j in range(k)]
    
    pos = 0
    for i in range(k):
        for j in range(k):
            A[i][j] += s[pos]
            pos += 1 
            
    A = list(zip(*A))
    for i in range(k):
        A[i] = list(reversed(list(A[i])))
        
    res = ""
    for i in range(k):
        for j in range(k):
            if A[i][j] != '*':
                res = res + A[i][j]
    
    print(res)
