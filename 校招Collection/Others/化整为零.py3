# https://ac.nowcoder.com/acm/problem/14515

def superDigit(n):
    if len(n) == 1:
        return n
    n = str(sum(map(int, list(n))))
    return superDigit(n)

try:
    while True:
        n = input()
        result = superDigit(n)
        print(result)
except:
    pass