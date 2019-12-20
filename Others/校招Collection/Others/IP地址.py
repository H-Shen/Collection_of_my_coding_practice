# https://www.nowcoder.com/practice/2359e23180194f99828f5cd9c764236a

table = set(xrange(256))

try:
    while 1:
        for _ in xrange(1):
            print 'Yes!' if all(map(lambda x:int(x) in table, raw_input().split('.'))) else 'No!'
except:
    pass