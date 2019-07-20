# https://www.nowcoder.com/practice/d83721575bd4418eae76c916483493de

def longest_increasing_subsequence_length(I):
    P = {0:[]}
    for i in I:
        for p in sorted(P):
            a = P[p]
            if a and i > a[-1]:
                    break
        P[p-1] = a + [i]
    return len(P[min(P)])

try:
    while 1:
        n = input()
        arr = map(int, raw_input().split())
        print longest_increasing_subsequence_length(arr)
except:
    pass