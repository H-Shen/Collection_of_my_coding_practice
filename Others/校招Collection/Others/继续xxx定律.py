# https://www.nowcoder.com/practice/9cc1055241c547269f58fa8b009e335d

def a(n):
    keyList.append(n)
    while n > 1:
        if (n & 1) == 0:
            n = n >> 1
            if n != 1:
                includeList.append(n)
        else:
            n = ((n << 2) - n + 1) >> 1
            if n != 1:
                includeList.append(n)

try:
    while 1:
        n = input()
        if n == 0:
            break
        keyList, includeList = [], []
        arr = map(int, raw_input().split())
        for i in arr:
            a(i)
        print ' '.join(map(str, sorted(set(keyList).difference(set(includeList)), key=arr.index)[::-1]))
except:
    pass