# https://www.nowcoder.com/practice/a5edebf0622045468436c74c3a34240f

from itertools import product
try:
    while 1:
        a, b = raw_input().split()
        print sum(map(lambda x:int(x[0]) * int(x[1]), list(product(a,b))))
except:
    pass