# https://www.nowcoder.com/practice/2aa32b378a024755a3f251e75cbf233a

def encrypt(s):
    r = ''
    for i in s:
        if i.isupper():
            if i == 'Z':
                r += 'a'
            else:
                r += chr(ord(i) + 33)
        elif i.islower():
            if i == 'z':
                r += 'A'
            else:
                r += chr(ord(i) - 31)
        elif i.isdigit():
            if i == '9':
                r += '0'
            else:
                r += str(int(i) + 1)
        else:
            r += i
    return r

def decrypt(s):
    r = ''
    for i in s:
        if i.isupper():
            if i == 'A':
                r += 'z'
            else:
                r += chr(ord(i) + 31)
        elif i.islower():
            if i == 'a':
                r += 'Z'
            else:
                r += chr(ord(i) - 33)
        elif i.isdigit():
            if i == '0':
                r += '9'
            else:
                r += str(int(i) - 1)
        else:
            r += i
    return r

try:
    while 1:
        print encrypt(raw_input())
        print decrypt(raw_input())
except:
    pass