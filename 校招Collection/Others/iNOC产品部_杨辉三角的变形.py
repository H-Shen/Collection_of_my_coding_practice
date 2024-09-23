# https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43

try:
    while 1:
        n = input()
        if n == 1 or n == 2:
            print -1
        elif n % 2 != 0:
            print 2
        elif (n - 1) % 4 == 3:
            print 3
        else:
            print 4
except:
    pass