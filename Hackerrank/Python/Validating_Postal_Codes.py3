MIN = 100000
MAX = 999999

n = input()
try:
    a = int(n)
except:
    print('False')
else:
    while MIN <= a <= MAX:
        L = [bool(n[0] == n[2]),bool(n[1] == n[3]),bool(n[2] == n[4]),bool(n[3] == n[5])]
        while L.count(True) <= 1:
            print('True')
            break
        else:
            print('False')
        break
    else:
        print('False')
