# https://www.nowcoder.com/practice/729d11d043d8448e83befa1410b694fe

try:
    while 1:
        for i in raw_input():
            s = bin(ord(i))[2:]
            if len(s) < 7:
                s = s.zfill(7)
            if s.count('1') % 2 == 0:
                s = '1' + s
            else:
                s = '0' + s
            print s
except:
    pass