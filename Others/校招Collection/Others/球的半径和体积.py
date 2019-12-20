# https://www.nowcoder.com/practice/4b733a850c364c32b368555c8c2ec96b

import math
pi = math.acos(-1)
try:
    while 1:
        x0, y0, z0, x1, y1, z1 = map(float, raw_input().split())
        R = ((x0-x1)**2 + (y0-y1)**2 + (z0-z1)**2) ** 0.5
        V = 4*pi*R**3/3
        R = "%.3f" %R
        V = "%.3f" %V
        print R, V
except:
    pass
