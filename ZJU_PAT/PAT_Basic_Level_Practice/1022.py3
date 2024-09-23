a, b, c = list(map(int, input().split()))
s = a + b
res = ""

while (s > 0):
    res = str(s % c) + res
    s //= c
    
if (res == ""):
    print(0)
else:
    print(res)