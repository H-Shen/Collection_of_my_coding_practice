try:
    while True:
        A, B = raw_input().split()
        m, n = set(A), set(B)
        Flag = True
        if m & n == n:
            for i in n:
                if B.count(i) > A.count(i):
                    Flag = False
                    break
            if Flag == True:
                print "Yes"
            else:
                print "No"
        else:
            print "No"
except:
    pass
