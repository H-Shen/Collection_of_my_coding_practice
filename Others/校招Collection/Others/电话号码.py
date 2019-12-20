# https://www.nowcoder.com/practice/ceb89f19187b4de3997d9cdef2d551e8

table = {k: v for i in [dict.fromkeys('ABC',2), dict.fromkeys('DEF',3), dict.fromkeys('GHI',4),
                       dict.fromkeys('JKL',5), dict.fromkeys('MNO',6), dict.fromkeys('PRQS',7)
                       , dict.fromkeys('TUV',8), dict.fromkeys('WXYZ',9)] for k, v in i.items()}

def transform(x):
    x = ''.join(x.split('-'))
    result = ''
    for char in x:
        if char in table:
            result += str(table[char])
        else:
            result += char
    result = result[:3] + '-' + result[3:]
    return result

try:
    while 1:
        contact = list()
        for j in xrange(input()):
            contact.append(transform(raw_input()))
        result = sorted(set(contact))
        for w in result:
            print w
       	print ''
except:
    pass