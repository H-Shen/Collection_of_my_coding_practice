from itertools import groupby

a = [list(g) for k, g in groupby(input())]

for i in range(len(a)):
    print((len(a[i]), int(a[i][0])),end = ' ')
