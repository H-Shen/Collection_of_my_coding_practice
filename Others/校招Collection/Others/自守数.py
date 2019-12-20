# https://www.nowcoder.com/practice/88ddd31618f04514ae3a689e83f3ab8e

try:
    while 1:
        s = input()
        print len(filter(lambda x:x < s, [1,5,6,25,76,376,625,9376,90625,109376,890625,2890625,7109376,12890625])) + 1
except:
    pass