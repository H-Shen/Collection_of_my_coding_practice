from string import ascii_lowercase
A = list(ascii_lowercase)

def hasDuplicate(s):
    for ch in A:
        if ch * 2 in s:
            return ch
    return False


a = input()

while True:
    ch = hasDuplicate(a)
    if ch == False:
        break
    a = a.replace(ch * 2, '')

if a == '':
    print('Empty String')
else:
    print(a)