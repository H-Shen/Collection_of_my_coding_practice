# https://open.kattis.com/problems/bits
a = int(input())
for i in range(a):
    maxCnt = 0
    num = input()
    num_str = ""
    for i in range(len(num)):
        num_str += num[i]
        maxCnt = max(bin(int(num_str)).count('1'), maxCnt)
    print(maxCnt)
