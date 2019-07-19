# https://www.nowcoder.com/practice/e3d8d4dd9ec740f9b1e7fc1e8574ba21

try:
    while 1:
        x, y = map(int, raw_input().split())
        if y != x and y != x - 2:
            print 'No Number'
        else:
            print x + y if (x & 1) == 0 else x + y - 1
except:
    pass