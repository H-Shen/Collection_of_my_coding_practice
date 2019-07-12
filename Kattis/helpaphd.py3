# https://open.kattis.com/problems/helpaphd
n = int(input())
for i in range(n):
    s = input()
    if s == "P=NP":
        print("skipped")
    else:
        print(eval(s))
