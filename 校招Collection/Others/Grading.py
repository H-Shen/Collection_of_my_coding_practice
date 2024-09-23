# https://www.nowcoder.com/practice/23e3244406724ffa8330760f640c8149

try:
    while 1:
        P, T, G1, G2, G3, GJ = map(int, raw_input().split())
        if abs(G1 - G2) <= T:
            result = (G1 + G2) / 2.0
        elif (abs(G3 - G1) <= T and abs(G3 - G2) <= T):
            result = max([G1, G2, G3])
        elif (abs(G3 - G1) > T and abs(G3 - G2) > T):
            result = GJ
        elif abs(G3 - G1) > abs(G3 - G2):
            result = (G3 + G2) / 2.0
        else:
            result = (G3 + G1) / 2.0
        print '%.1f' % result
except:
    pass