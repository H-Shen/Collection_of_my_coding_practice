# https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201

table = {}
for i in xrange(input()):
    x, y = map(int, raw_input().split())
    table[x] = y if not x in table else table[x] + y
res = sorted(table.items(),key=lambda x:x[0])
for j in res:
    print ' '.join(map(str, j))