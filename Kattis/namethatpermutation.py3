# https://open.kattis.com/problems/namethatpermutation
A = [1, 1]

counter = 2
while (len(A) <= 55):
    A.append(A[-1] * counter)
    counter += 1
    
def reverseCantorExpansion(s, k):
    
    length = len(s)
    vis = [False for i in range(length + 1)]
    
    global A
    k -= 1
    for i in range(length):
        t = k // A[length - i - 1]
        for j in range(1, length + 1):
            if not vis[j]:
                if t == 0:
                    break
                t -= 1
        s[i] = j
        vis[j] = True
        k %= A[length - i - 1]
        
    return s

try:
    while True:
        n, k = list(map(int, input().split()))
        s = [0 for i in range(n)]
        s = reverseCantorExpansion(s, k + 1)
        print(' '.join(list(map(str, s))))
except:
    pass
