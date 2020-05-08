def average(b):
    a = len(b)
    for i in range(len(b)):
        b[i] = int(b[i])

    c = set(b)
    a = a - (len(b) - len(c))
    d = sum(c)
    return d / a

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)