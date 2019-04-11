a, b = list(map(int, input().split()))
s = str(a * b)[::-1]

if s != '0':
  s = s.lstrip('0')
print(s)