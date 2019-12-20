# https://www.nowcoder.com/practice/3ab09737afb645cc82c35d56a5ce802a

import math

num = input()
a = math.floor(num)

if num - a >= 0.5:
    print int(a) + 1
else:
    print int(a)