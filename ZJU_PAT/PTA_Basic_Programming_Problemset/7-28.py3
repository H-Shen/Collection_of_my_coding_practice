def Monkey(n, M):

    # Use boolean to represent 2 different status
    L = list(map(list,list(enumerate([True] * n,start=1))))
    counter = 0
    while [L[i][1] for i in range(len(L))].count(True) > 1:
        for i in range(len(L)):
            if L[i][1] == True:
                counter += 1
            if counter % M == 0 and L[i][1] == True:
                L[i][1] = False
    return list(filter(lambda x:x[1] == True, L))[0][0]

print(Monkey(int(input()), 3))