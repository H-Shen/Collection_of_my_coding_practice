table = {}
 
def a(n):
    global a
    while n != 1:
        if (n & 1) == 0:
            n = (n >> 1)
        else:
            n = ((3 * n + 1) >> 1)
        if not n in table:
            table[n] = 0
    return None
         
             
K = input()
L = map(int, raw_input().split())
 
for i in L:
    if not i in table:
        _ = a(i)
         
print ' '.join(map(str, sorted(set(L).difference(set(table.keys())), reverse=True)))