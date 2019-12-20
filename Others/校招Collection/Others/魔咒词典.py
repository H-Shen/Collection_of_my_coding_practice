# https://www.nowcoder.com/practice/c6ca566fa3984fae916e6d7beae8ea7f

try:
    while 1:
        a, b = {}, {}
        while 1:
            Item = raw_input()
            if Item == '@END@':
                break
            Index = Item.index(']')
            Word, Function = Item[:Index + 1], Item[Index + 2:]
            a[Word], b[Function] = Function, Word
       	for i in xrange(input()):
            Query = raw_input()
            if Query in a:
                print a[Query]
            elif Query in b:
                print b[Query][1: -1]
            else:
                print 'what?'
except:
    pass