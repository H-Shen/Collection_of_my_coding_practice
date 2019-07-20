# https://www.nowcoder.com/practice/e8480ed7501640709354db1cc4ffd42a

try:
    while 1:

        s = raw_input()
        num = input()
        length = len(s)
        maxVal = -1

        for i in xrange(length - num + 1):
            currentStr = s[i:i + num]
            count = currentStr.count('G') + currentStr.count('C')
            if count > maxVal:
                maxVal = count

        for i in xrange(length - num + 1):
            currentStr = s[i:i + num]
            count = currentStr.count('G') + currentStr.count('C')
            if count == maxVal:
                print currentStr
                break
except:
    pass