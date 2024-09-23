# https://www.nowcoder.com/practice/a3417270d1c0421587a60b93cdacbca0

from datetime import datetime

Month = {'May': 5, 'December': 12, 'October': 10, 'August': 8,
         'July': 7, 'February': 2, 'January': 1, 'September': 9,
         'March': 3, 'April': 4, 'November': 11, 'June': 6}

try:
    while 1:
        k = raw_input().split()
        print datetime(int(k[2]),Month[k[1]],int(k[0])).strftime('%A').capitalize()
except:
    pass