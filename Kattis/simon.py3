# https://open.kattis.com/problems/simon

n = int(input())
for i in range(n):
    s = input()
    if s.startswith("simon says "):
        print(s[11:])
    else:
        print()
