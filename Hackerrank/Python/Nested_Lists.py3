Name = list()
Grades = list()
N = int(input())
for i in range(N):
    nameInput = input()
    gradeInput = float(input())
    Name.append(nameInput)
    Grades.append(gradeInput)

result = list(zip(Name, Grades))

for x in range(N):
    result[x] = list(result[x])

minimum = min(Grades)
maximum = max(Grades)

for j in range(N):
    if Grades[j] == minimum:
        Grades[j] = maximum + 1
        result[j][1] = maximum + 1

minimum2 = min(Grades)
resultName = []

for k in range(N):
    if Grades[k] == minimum2:
        resultName.append(result[k][0])

resultName.sort()

for y in resultName:
    print(y)
