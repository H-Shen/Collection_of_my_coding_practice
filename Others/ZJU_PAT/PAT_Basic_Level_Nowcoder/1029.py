from datetime import datetime
try:
    while 1:
        result, year = [], input()
        for i in xrange(1, 13):
            if datetime(year , i , 13).strftime('%A') == 'Friday':
                result.append(str(i))
        print 'Luck' if result == [] else ' '.join(result)
except:
    pass