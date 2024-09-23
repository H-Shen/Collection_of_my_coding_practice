# https://www.nowcoder.com/practice/d9aa3894d3aa4887843a85d26daa4437

def f(s):
    a, L = [], len(s)
    for i in xrange(L):
        if s[i].isalpha():
            a.append((s[i], s[i].lower(), i))
    b = sorted(a, key=lambda x:(x[1], x[2], x[0]))
    result = ''
    for i in xrange(L):
        if s[i].isalpha():
            result += b[0][0]
            del b[0]
        else:
            result += s[i]
    return result

try:
    while 1:
        print f(raw_input())
except:
    pass