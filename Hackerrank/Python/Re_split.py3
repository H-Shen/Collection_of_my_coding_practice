import re
k = re.split(',',input())
for y in range(len(k)):
    if '.' in k[y]:
        k[y] =  re.split('\.',k[y])

flatten = lambda x: [y for l in x for y in flatten(l)] if type(x) is list else [x]
k = flatten(k)

for y in k:
    if y != '':
        print(y)