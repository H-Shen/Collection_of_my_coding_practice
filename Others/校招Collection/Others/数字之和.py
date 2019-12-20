# https://www.nowcoder.com/practice/ae759916631f4711a90c4d4d9657f4b0

try:
    while 1:
        n = input()
        if n == 0:
            break
        else:
            print sum(map(int, str(n))), sum(map(int, str(n ** 2)))
except:
    pass