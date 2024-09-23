# https://www.nowcoder.com/practice/a988eda518f242c29009f8620f654ede

try:
    while 1:
        s = raw_input()
        for i in xrange(input()):
            query = raw_input()
            if query[0] == '0':
                start = int(query[1])
                length = int(query[2])
                s = s[:start] + s[start:start + length][::-1] + s[start + length:]
            else:
                start = int(query[1])
                length = int(query[2])
                content = query[3:]
                s = s[:start] + content + s[start + length:]
            print s
except:
    pass