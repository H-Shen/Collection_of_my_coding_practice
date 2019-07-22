# https://www.nowcoder.com/practice/dc6a75a15d1948edafa6d63bc8fc2368

import sys

while 1:
    x, y = map(int, raw_input().split())
    max_x, min_x, max_y, min_y = x, x, y, y
    if x == y == 0:
        print min_x, min_y, max_x, max_y
        sys.exit()
    while 1:
        x, y = map(int, raw_input().split())
        if x == y == 0:
            print min_x, min_y, max_x, max_y
            sys.exit()
        if x > max_x:
            max_x = x
        elif x < min_x:
            min_x = x
        if y > max_y:
            max_y = y
        elif y < min_y:
            min_y = y