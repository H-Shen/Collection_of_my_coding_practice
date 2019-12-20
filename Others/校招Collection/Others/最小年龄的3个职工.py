# https://www.nowcoder.com/practice/a9fa482eb05149cdbad88689e3cb5f66

try:
    while 1:
        table = list()
        for _ in range(input()):
            table.append(raw_input().split())
        result = sorted(table,key=lambda x:(int(x[-1]),int(x[0]),x[1]))[:3]
        for i in result:
            print ' '.join(i)
except:
    pass