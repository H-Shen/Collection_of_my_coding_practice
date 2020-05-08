S = input()
itemS = list(set(S))
countS = list()

for i in range(len(itemS)):
    countS.append(S.count(itemS[i]))

countSSet = sorted(list(set(countS)))
countSSet.reverse()

result1 = list()
result2 = list()
result3 = list()
result = list()

try:
    for i in range(len(itemS)):
        if S.count(itemS[i]) == countSSet[0]:
            result1.append((itemS[i], countSSet[0]))

    result1.sort()

    for i in range(len(itemS)):
        if S.count(itemS[i]) == countSSet[1]:
            result2.append((itemS[i], countSSet[1]))

    result2.sort()

    for i in range(len(itemS)):
        if S.count(itemS[i]) == countSSet[2]:
            result3.append((itemS[i], countSSet[2]))

    result3.sort()

except:
    pass

result = result1 + result2 + result3

for j in range(3):
    print(str(result[j][0]) + ' ' + str(result[j][1]))
