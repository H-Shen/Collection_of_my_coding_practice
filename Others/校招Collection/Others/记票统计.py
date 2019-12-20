# https://www.nowcoder.com/practice/3350d379a5d44054b219de7af6708894

from collections import OrderedDict

try:
    while 1:
        n = input()
        arr = raw_input().split()
        m = input()
        L = raw_input().split()

        table = OrderedDict()
        for i in arr:
            table[i] = 0
        invalid = 0
        for j in L:
            if j in table:
                table[j] += 1
            else:
                invalid += 1
        for k in table:
            print k + ' : ' + str(table[k])
        print 'Invalid : ' + str(invalid)
except:
    pass