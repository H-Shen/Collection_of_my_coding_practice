# https://www.nowcoder.com/practice/480d2b484e1f43af8ea8434770811b4a

try:
    while True:
        n = int(input())
        if n == 0:
            break
        print(pow(5, n) - 4, pow(4, n) + n - 4)
except:
    pass