# https://www.nowcoder.com/practice/f4e2fc37f9a54787a7c2846873e8b827

s = {'2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'}
s_cmp = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']

def handle(stra):
    a, length = [], len(stra)
    if length == 3:
        a = map(str, stra)
    elif length == 4:
        stra = stra.replace("10", "")
        a.extend(["10", stra[0], stra[1]])
    elif length == 5:
        stra = stra.replace("10", "")
        a.extend(["10", "10", stra[0]])
    else:
        return False

    for i in a:
        if not i in s:
            return False
    return a

def level(a):
    temp = set(a)
    if len(temp) == 1:
        return 3
    elif temp == {'2', '3', '4'} or temp == {'4', '5', '6'} or temp == {'5', '6', '7'} or  \
         temp == {'7', '8', '9'} or temp == {'8', '9','10'} or temp == {'10', 'J','Q'} or  \
         temp == {'J', 'Q', 'K'}:
        return 2
    elif len(temp) == 2:
        return 1
    return 0

def sieve(a):
    if a[0] == a[1]:
        a_pair, a_single = a[0], a[2]
    else:
        a_pair, a_single = a[1], a[0]
    return [s_cmp.index(a_pair), s_cmp.index(a_single)]

try:
    while 1:

        a, b = map(handle, raw_input().split())
        if a == False or b == False:
            print -2
        else:
            levela, levelb = level(a), level(b)
            if levela > levelb:
                print 1
            elif levela < levelb:
                print -1
            else:
                a.sort(key=s_cmp.index)
                b.sort(key=s_cmp.index)

                if levela == 3 or levela == 2:

                    if a[2] == b[2]:
                        print 0
                    elif s_cmp.index(a[2]) > s_cmp.index(b[2]):
                        print 1
                    else:
                        print -1

                elif levela == 1:

                    a_pair, a_single = sieve(a)
                    b_pair, b_single = sieve(b)

                    if a_pair == b_pair and a_single == b_single:
                        print 0
                    elif a_pair == b_pair and a_single > b_single:
                        print 1
                    elif a_pair == b_pair and a_single < b_single:
                        print -1
                    elif a_pair > b_pair:
                        print 1
                    elif a_pair < b_pair:
                        print -1


                else:
                    for i in range(2, -1, -1):
                        if a[i] == b[i]:
                            continue
                        elif s_cmp.index(a[i]) > s_cmp.index(b[i]):
                            print 1
                            break
                        else:
                            print -1
                            break
except:
    pass