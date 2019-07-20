# https://www.nowcoder.com/practice/bd62095a03a545729cdbfc506e0da952

try:
    while 1:
        n = input()
        A = [tuple(map(int, raw_input().split())) for i in xrange(n)]
        B = [tuple(map(int, raw_input().split())) for j in xrange(n)]
        if B == A:
            print 0
        elif B == list(zip(*A[::-1])):
            print 90
        elif B == [i[::-1] for i in A[::-1]]:
        	print 180
        elif B == list(zip(*A))[::-1]:
        	print 270
        else:
            print -1
except:
    pass