from datetime import datetime
k = input().split()

if k[0][0] == '0':
    k[0] = k[0][1]

if k[1][0] == '0':
    k[1] = k[1][1]

print(datetime(int(k[2]),int(k[0]),int(k[1])).strftime('%A').upper())
