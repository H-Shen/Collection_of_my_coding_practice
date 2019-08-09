# https://ac.nowcoder.com/acm/problem/15234

n = int(input())
A = list()
for i in range(9):
    A.append(input())
A = list(zip(*A))

B = list()
for i in A:
    B.append(''.join(i))

res = ""
for i in B:
    pos = i.find("o")
    if pos == -1:
        res += "|"
    elif pos == 0 or pos == 7:
        res += "F"
    elif pos == 1 or pos == 8:
        res += "E"
    elif pos == 2:
        res += "D"
    elif pos == 3:
        res += "C"
    elif pos == 4:
        res += "B"
    elif pos == 5:
        res += "A"
    elif pos == 6:
        res += "G"
print(res)