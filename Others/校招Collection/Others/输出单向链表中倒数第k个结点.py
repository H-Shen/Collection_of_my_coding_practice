# https://www.nowcoder.com/practice/54404a78aec1435a81150f15f899417d

try:
    while 1:
        n = input()
        arr = map(int, raw_input().split())
        k = input()
        try:
            if k == 0:
                print 0
            else:
            	print arr[-k]
        except:
            print ''
except:
    pass