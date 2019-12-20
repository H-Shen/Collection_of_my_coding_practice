# https://www.nowcoder.com/practice/8c3c5dae2c4a4266ba04f993a18e286b

try:
    while 1:
        A, B, K = raw_input().split()
        if A == B == '0':
            break
        K = int(K)
        if K == 0:
            print -1
        elif int(A[-K:]) == int(B[-K:]):
            print -1
        else:
            print int(A) + int(B)
except:
    pass