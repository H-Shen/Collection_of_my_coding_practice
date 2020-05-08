from fractions import Fraction as F

def postprocess(n):
    if n.denominator == 1:
        return str(n.numerator) + '/1'
    else:
        return n

for i in range(int(input())):
    A, B, C = list(map(int,input().split()))
    p, q = max([A, B]),min([A, B])

    if A + B < C:
        result = F(1, 1)
    elif C <= A and C <= B:
        result = F(C ** 2, 2 * A * B)
    elif q <= C <= p:
        result = F((2 * C - q) * q, 2 * A * B)
    else:
        result = F(1) - F((A + B - C) ** 2, 2 * A * B)

    result = postprocess(result)
    print(result)
