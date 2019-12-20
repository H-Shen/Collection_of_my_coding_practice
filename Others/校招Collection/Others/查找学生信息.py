# https://www.nowcoder.com/practice/fe8bff0750c8448081759f3ee0d86bb4

class Student:
    def __init__(self, ID, name, sex, age):
        self.ID = ID
        self.name = name
        self.sex = sex
        self.age = age

def find(student, number):
    for i in range(len(student)):
        if number == student[i].ID:
            return i
    return -1

while 1:
    try:
        n = input()
        student = [0] * n
        for i in xrange(n):
            ID, name, sex, age = raw_input().split()
            student[i] = Student(ID, name, sex, age)
        m = input()
        for i in xrange(m):
            number = raw_input()
            index = find(student, number)
            if index != -1:
                student[index]
                print student[index].ID, student[index].name, student[index].sex, student[index].age
            else:
                print 'No Answer!'
    except:
        break