import re
a = list()

for i in range(int(input())):
    a.append(input())
sentence = ' '.join(a)
for j in range(int(input())):
    keyword = input()
    print(len(re.findall(r'\w{word}\w'.format(word = keyword), sentence)))


