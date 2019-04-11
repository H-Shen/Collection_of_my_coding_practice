a = {'B': 'W', 'G': 'B', 'Q': 'L', 'O': 'J', 'Y': 'T', 'D': 'Y', 'K': 'F', 'L': 'G', 'A': 'V', 'T': 'O', 'H': 'C', 'V': 'Q', 'I': 'D', 'M': 'H', 'P': 'K', 'J': 'E', 'E': 'Z', 'S': 'N', 'Z': 'U', 'R': 'M', 'X': 'S', 'U': 'P', 'C': 'X', 'N': 'I', 'W': 'R', 'F': 'A'}
try:
    while 1:
        b = raw_input()
        c = ''
        for i in b:
            if i in a:
                c += a[i]
            else:
                c += i
        print c
except:
    pass