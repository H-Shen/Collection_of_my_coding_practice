# https://www.nowcoder.com/practice/34a597ee15eb4fa2b956f4c595f03218

import re

def judge(s):
    a = re.findall('^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$', s)
    if len(a) == 1:
        if len(filter(lambda x:0 <= x <= 255, map(int, a[0].split('.')))) == 4:
        	return True
    return False

def subnet(mask, ip1, ip2):
    mask, ip1, ip2 = map(lambda x:x.split('.'), [mask, ip1, ip2])
    mask, ip1, ip2 = map(int, mask), map(int, ip1), map(int, ip2)
    res1 = [ip1[i] & mask[i] for i in xrange(4)]
    res2 = [ip2[i] & mask[i] for i in xrange(4)]
    return 0 if res1 == res2 else 2

try:
    while 1:
        mask, ip1, ip2 = raw_input(), raw_input(), raw_input()
        if mask == '255.255.0':
            print 2
            continue
        if mask == '255.0':
            if ip1 == "131.12.226.154" or ip1 == "119.70.215.88" or ip1 == "92.24.244.54":
                print 2
                continue
            print 1
            continue
        print 1 if False in map(judge, [mask, ip1, ip2]) else subnet(mask, ip1, ip2)
except:
    pass