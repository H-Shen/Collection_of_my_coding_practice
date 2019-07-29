# https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4

from collections import OrderedDict

try:
    while 1:
        a, flag = OrderedDict(), 0
        for i in raw_input():
            if not i in a:
                a[i] = 1
            else:
                a[i] += 1
        for j, k in a.items():
            if k == 1:
                print j
                flag = 1
                break
        if flag == 0:
            print -1
except:
    pass