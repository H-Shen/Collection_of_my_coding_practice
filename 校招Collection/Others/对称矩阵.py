# https://www.nowcoder.com/practice/ad11ebc8d44842c78bb0bbfb6d07ad7a

try:
    while 1:
        m = list()
        for _ in range(input()):
            m.append(tuple(raw_input().split()))
        print 'Yes!' if m == zip(*m) else 'No!'
except:
    pass