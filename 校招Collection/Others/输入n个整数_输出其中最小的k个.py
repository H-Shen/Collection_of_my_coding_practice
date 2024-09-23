# https://www.nowcoder.com/practice/69ef2267aafd4d52b250a272fd27052c

from heapq import nsmallest as f

try:
    while 1:
        n, k = map(int, raw_input().split())
        print ' '.join(map(str, f(k, map(int, raw_input().split()))))
except:
    pass