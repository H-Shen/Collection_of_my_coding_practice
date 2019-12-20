# https://www.nowcoder.com/practice/539054b4c33b4776bc350155f7abd8f5

try:
    while 1:
        Chr, Space, Num, Other = [0] * 4
        for i in raw_input():
            if i.isalpha():
                Chr += 1
            elif i.isdigit():
                Num += 1
            elif i == ' ':
                Space += 1
            else:
                Other += 1
        for j in [Chr, Space, Num, Other]:
            print j
except:
    pass