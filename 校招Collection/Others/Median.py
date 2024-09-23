# https://www.nowcoder.com/practice/b5da3f56557f42978ca87afedbd85fbe

try:
    while 1:
        A = map(int, raw_input().split())
        lenA, A = A[0], A[1:]
        B = map(int, raw_input().split())
        lenB, B = B[0], B[1:]
        C, lenC = sorted(A + B), lenA + lenB
        if lenC % 2 != 0:
            print C[(lenC - 1) / 2]
        else:
            print (C[lenC / 2 - 1])
except:
    pass