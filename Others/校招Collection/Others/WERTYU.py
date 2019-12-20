# https://www.nowcoder.com/practice/0f318e6fffe3490cb700e16b65a93b1b

a = "1234567890-=WERTYUIOP[]\SDFGHJKL;'XCVBNM,./"
b = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,."

table = dict(zip(a, b))
try:
    while 1:
        s = raw_input()
        output = ''
        for i in s:
            if i in table:
                output += table[i]
            else:
                output += i
        print output
except:
    pass