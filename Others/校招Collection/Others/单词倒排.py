# https://www.nowcoder.com/practice/81544a4989df4109b33c2d65037c5836

from string import ascii_letters
a = ascii_letters + ' '

try:
    while 1:
        s = raw_input()
        result = ''
        for i in s:
            if i in a:
            	result += i
            else:
                result += ' '
        print ' '.join(result.split()[::-1])
except:
    pass