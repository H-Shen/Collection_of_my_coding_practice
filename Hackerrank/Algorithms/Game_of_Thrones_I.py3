from collections import Counter

s = input()

Dict = Counter(s)
item = list(Dict.keys())
count = list(Dict.values())

if len(s) % 2 == 0:
    if all([x % 2 == 0 for x in count]):
        print('YES')
    elif [x % 2 == 0 for x in count].count(False) == 1:
        print('YES')
    else:
        print('NO')

else:
    if [x % 2 == 0 for x in count].count(False) == 1:
        print('YES')
    else:
        print('NO')
