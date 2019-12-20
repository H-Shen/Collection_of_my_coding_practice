# https://www.nowcoder.com/practice/53e4c208b8cf497086ecd65ef45349bb

n = int(input())
h = int(n ** 0.5) + 1
while 1:
    if h * (h + 1) > n:
        h -= 1
    else:
        break
print(h)