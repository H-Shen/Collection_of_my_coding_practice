# https://www.nowcoder.com/practice/641ddd0fb98b406690a086e3f36b20b1

try:
    while 1:
        n = input()
        a = []
        for i in xrange(n):
            s = raw_input().split()
            s.append(s[0].lower())
            s.append(s[1].lower())
            a.append(s)
        a.sort(key=lambda x:(x[-1], x[-2]))
        for q, w, e, r in a:
            print q
        print ''
except:
    pass