# https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d

from datetime import datetime, timedelta

n = int(input())
for i in range(n):
    y, m, d, delta = list(map(int, input().split()))
    result = datetime(y, m, d)+timedelta(days=delta)
    print(result.strftime("%Y-%m-%d"))