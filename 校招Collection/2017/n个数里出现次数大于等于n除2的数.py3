# https://www.nowcoder.com/practice/eac8c671a0c345b38aa0c07aba40097b
k = dict()
a = input().split()
len_a = len(a)

for i in a:
    if i not in k:
        k[i] = 1
    else:
        k[i] += 1
        if k[i] == len_a // 2:
            print(i)
            break
