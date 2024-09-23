# https://www.nowcoder.com/practice/069e2130430c41229ab25e47fa0949a6

try:
    while 1:
        n = input()
        L = map(int, raw_input().split())
        try:
        	print L.index(input())
        except:
            print -1
except:
    pass