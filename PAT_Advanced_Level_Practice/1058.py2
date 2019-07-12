def GSKtoK(GSKString):
    G, S, K = map(int, GSKString.split('.'))
    return G * 17 * 29 + 29 * S + K

def KtoGSK(num):
    K = num % 29
    S = ((num - K) // 29) % 17
    G = ((num - K) // 29 - S) // 17
    return str(G) + '.' + str(S) + '.' + str(K)


try:
    while 1:
        a, b = raw_input().split()
        c = GSKtoK(a) + GSKtoK(b)
        d = KtoGSK(c)
        print d
except:
    pass