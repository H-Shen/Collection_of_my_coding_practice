# https://www.nowcoder.com/practice/ff99c43dd07f4e95a8f2f5448da3772a

a = 'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z'.split()
b = 'V W X Y Z A B C D E F G H I J K L M N O P Q R S T U'.split()
table = dict(zip(a, b))

try:
    while 1:
        s = raw_input()
        if s == 'ENDOFINPUT':
            break
        if s == 'START' or s == 'END':
            continue
        output = ''
        for i in s:
            if i in table:
                output += table[i]
            else:
                output += i
        print output
except:
    pass