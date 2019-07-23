n = int(input())
s = ''
for i in range(n):
    s += ' ' + input()
t = int(input())
table = {}
for j in range(t):
    w = input()
    w2 = w.replace('our', 'or')
    num = s.count(w) + s.count(w2)

    for i in table.keys():
        if w in i:
            num -= table[i]
    table[w] = num

    print(num)
