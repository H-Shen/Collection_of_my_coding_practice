from collections import Counter
def isPerm(strn):
    return Counter(strn) == Counter(str(int(strn) * 2))

s = input()
a = int(s)
b = a * 2

if (isPerm(s)):
    print("Yes")
else:
    print("No")
print(b)