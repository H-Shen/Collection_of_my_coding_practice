from fractions import Fraction as f
n = int(input())
print(sum(list(map(f, input().split()))) / n)