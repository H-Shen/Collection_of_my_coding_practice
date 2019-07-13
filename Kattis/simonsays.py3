# https://open.kattis.com/problems/simonsays

for i in range(int(input())):
    a = input()
    if a.startswith("Simon says"):
        print(a[11:])
