# https://www.nowcoder.com/practice/784efd40ed8e465a84821c8f3970b7b5

try:
    while 1:
        s = raw_input()
        print ''.join(sorted(set(s), key=s.index))
except:
    pass