# https://www.nowcoder.com/practice/e91982a145944ceab6bb9a4a508e0e26

try:
    while 1:
        Stack = []
        N = input()
        if N == 0:
            break
        for i in xrange(N):
            a = raw_input().split()
            if a[0] == 'O' and len(Stack) != 0:
                Stack.pop()
            elif a[0] == 'A':
                if len(Stack) == 0:
                    print 'E'
                else:
                    print Stack[-1]
            elif a[0] == 'P':
                Stack.append(a[1])
        print ''
except:
    pass