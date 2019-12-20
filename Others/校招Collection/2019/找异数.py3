# https://www.nowcoder.com/practice/596eb514664b415994c843c2e489aba8

from collections import defaultdict

A = defaultdict(list)
B = dict()
counter = 0

while 1:
    s = input()
    if (s == "END"):
        break
    if (s not in B):
        B[s] = counter
        counter += 1
    n, m = s.split("#")
    n = int(n)
    A[int(m, n)].append(s)

haveAns = False
C = list()
for i, j in A.items():
    if (len(j) == 1):
        haveAns = True
        C.append((j[0], B[j[0]]))

if not haveAns:
    print("None")
else:
    C.sort(key=lambda x: x[1])
    for i, j in C:
        print(i)