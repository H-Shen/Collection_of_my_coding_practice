# https://www.nowcoder.com/practice/5fb3548802bb4a13a10c2e53a6fbfdd9

a = {'five': '5', 'three': '3', 'seven': '7', 'zero': '0', 'nine': '9', 'two': '2', 'eight': '8', 'four': '4', 'six': '6', 'one': '1'}

try:
    while 1:
        s = raw_input().split()
        Plus, Eq = s.index('+'), s.index('=')
        A = int(''.join(map(lambda x:a[x], s[:Plus])))
        B = int(''.join(map(lambda x:a[x], s[Plus + 1: Eq])))
        if A == B == 0:
            break
        print A + B
except:
    pass