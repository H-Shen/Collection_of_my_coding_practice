# https://www.nowcoder.com/practice/75c189249d6145cfa33cd53edae6afc8

try:
    while 1:
        n = input()
        if n == 0:
            break
        count = 0
        while n > 1:
            if (n & 1) == 0:
                n = n >> 1
            else:
                n = ((n << 2) - n + 1) >> 1
            count += 1
        print count
except:
    pass
