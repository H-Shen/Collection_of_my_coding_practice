import decimal

f = decimal.Decimal
result = {}
resultList = list()
N = int(input())
for i in range(N):
    string = input()
    resultList.append(string.split())
for j in range(N):
    resultList[j][1] = float(resultList[j][1])
    resultList[j][2] = float(resultList[j][2])
    resultList[j][3] = float(resultList[j][3])
name = input()
for k in range(N):
    if resultList[k][0] == name:
        avg = f((resultList[k][1] + resultList[k][2] + resultList[k][3])\
                 / 3)
print(round(avg, 2))
