# https://www.nowcoder.com/practice/3f27a0a5a59643a8abf0140b9a8cf1f7

try:
    while 1:
        a = list()
        for i in xrange(input()):
			a.append(map(int, raw_input().split()))
        a.sort(key=lambda x:(x[1], x[0]))
        for j, k in a:
            print j, k
except:
    pass