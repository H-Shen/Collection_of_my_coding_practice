# https://www.nowcoder.com/practice/66ca0e28f90c42a196afd78cc9c496ea

try:
    while 1:
        IP1 = raw_input()
        print int(''.join(map(lambda x: bin(x)[2:].zfill(8), map(int, IP1.split('.')))), 2)
        IP2 = input()
        print '.'.join(map(lambda x: str(int(x, 2)), [bin(IP2)[2:].zfill(32)[i:i + 8] for i in range(0, 32, 8)]))
except:
    pass