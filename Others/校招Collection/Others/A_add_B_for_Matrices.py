# https://www.nowcoder.com/practice/e431b3ae9efa4726b45a659b71abe124

def ListAdd(a, b, length):
    return [a[i] + b[i] for i in xrange(length)]

try:
    while 1:
        L = map(int, raw_input().split())
        M = L[0]
        if M == 0:
            break
        N = L[1]
        A = [map(int, raw_input().split()) for i in xrange(M)]
        B = [map(int, raw_input().split()) for i in xrange(M)]
        S = [ListAdd(A[i], B[i], N) for i in xrange(M)]
        count = 0
        for j in S + zip(*S):
            if any(j) == False:
                count += 1
        print count
except:
    pass