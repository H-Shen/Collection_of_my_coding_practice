def check(s):
  return s == s[::-1]

cnt = 0
a = input()
haveAns = False

while (cnt < 10):
  if cnt == 0 and check(a):
    print(a + " is a palindromic number.")
    haveAns = True
    break
  b = str(int(a) + int(a[::-1]))
  if check(b):
    print(a + " + " + a[::-1] + " = " + b)
    print(b + " is a palindromic number.")
    haveAns = True
    break
  cnt += 1
  print(a + " + " + a[::-1] + " = " + b)
  a = b

if not haveAns:
  print("Not found in 10 iterations.")