# https://www.nowcoder.com/practice/c046a2eade034db58cdfdaf58f894489

try:
    while 1:
        a = round(sum([input() for i in xrange(12)]) / 12.0, 2)
        a = '%.2f' % a
        print '$' + str(a)
except:
    pass