# https://www.nowcoder.com/practice/3245215fffb84b7b81285493eae92ff0

try:
    while 1:
        n = int(input())
        A = set()
        for i in range(n):
            A.add(int(input()))
        A = sorted(list(A))
        Len = len(A)
        for i in range(Len):
            print(A[i])
except:
    pass