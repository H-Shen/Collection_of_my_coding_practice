try:
    while 1:
        a, b, c = sorted(map(int, raw_input().split()))
        print 'Yes' if a + b > c else 'No'
except:
    pass