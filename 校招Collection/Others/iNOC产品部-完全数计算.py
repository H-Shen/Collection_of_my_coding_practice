# https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84

def count(n):
    try:
        return -1 if (n < 0 or n > 500000) else len(list(filter(lambda x: x < n, [6, 28, 496, 8128])))
    except:
        return -1
try:
    while 1:
        print count(input())
except:
    pass