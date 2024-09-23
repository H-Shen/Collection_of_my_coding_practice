from collections import deque
try:
    while 1:
        n, m = map(int, raw_input().split())
        L = deque(raw_input().split())
        L.rotate(m)
        print ' '.join(L)
except:
    pass