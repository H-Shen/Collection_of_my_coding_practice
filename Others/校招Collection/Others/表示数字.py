# https://www.nowcoder.com/practice/637062df51674de8ba464e792d1a0ac6

try:
    while 1:
        a = raw_input()
        b = ''
        flag = False
        for i in a:
            if i.isdigit() and flag == False:
                b = b + '*' + i
                flag = True
            elif not i.isdigit() and flag == True:
                b = b + '*' + i
                flag = False
            else:
                b += i
        if a[-1].isdigit():
            b += '*'
        print b
except:
    pass