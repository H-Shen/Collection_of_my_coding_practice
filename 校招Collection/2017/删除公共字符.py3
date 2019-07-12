# https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212

a, b, s = input(), set(input()), ''
for i in a:
    if i not in b:
        s += i
print(s)