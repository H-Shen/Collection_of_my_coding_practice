# https://open.kattis.com/problems/whatdoesthefoxsay

n = int(input())
for i in range(n):
    s = input().split()
    Set = set()
    while 1:
        a = input()
        if a == "what does the fox say?":
            break
        animal, goes, sound = a.split()
        Set.add(sound)
    s_new = list()
    for i in s:
        if not i in Set:
            s_new.append(i)
    print(' '.join(s_new))
