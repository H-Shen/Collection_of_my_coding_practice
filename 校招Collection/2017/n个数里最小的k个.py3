# https://www.nowcoder.com/practice/cc727473d1e248ccb674eb31bd8683dc
import heapq

L = list(map(int, input().split()))
k = L.pop()

ans = list(heapq.nsmallest(k, L))
ans.sort()

print(' '.join(list(map(str, ans))))
