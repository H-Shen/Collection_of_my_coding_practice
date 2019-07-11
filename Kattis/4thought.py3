# https://open.kattis.com/problems/4thought

opList = ["+", "-", "*", "//"]
Dict = dict()

for i in opList:
    for j in opList:
        for k in opList:
            formula = "4 " + i + " 4 " + j + " 4 " + k + " 4"
            tmp = eval(formula)
            if not tmp in Dict:
                Dict[tmp] = formula
                
n = int(input())
for i in range(n):
    target = int(input())
    if not target in Dict:
        print("no solution")
    else:
        if "//" in Dict[target]:
            Dict[target] = Dict[target].replace("//", "/")
    print(Dict[target] + " = " + str(target))
