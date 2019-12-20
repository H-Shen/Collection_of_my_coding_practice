# https://www.nowcoder.com/practice/81d2608fdd644982801ae8ce88bd10a9

def findLongest(A, n):
    # write code here
    P = {0: []}
    for i in A:
        temp = sorted(P)
        for p in temp:
            a = P[p]
            if a and i > a[-1]:
                break
        P[p - 1] = a + [i]
    return len(P[min(P)])

A = list(map(int, input().split()))
print(findLongest(A, len(A)))