# https://www.nowcoder.com/practice/b84f3f63fb7b496182f9b0711061e357

try:
    while 1:
        m, n = map(int, raw_input().split())
        a = map(int, raw_input().split())
        b = map(int, raw_input().split())
        result = []
        flag = False
        for i in a:
            temp = abs(min(b, key=lambda x:abs(x - i)) - i)
            if temp == 0:
                flag = True
                print 0
                break
            else:
                result.append(temp)

        if flag == False:
            print min(result)
except:
    pass