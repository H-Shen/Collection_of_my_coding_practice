# https://www.nowcoder.com/practice/e3f67da21c3f45bfb091cf0cabb9bb0f

a = dict()
s = input()
L = len(s)

for i in range(L):
    if s[i].isalpha():
        if s[i] in a:
            a[s[i]] += 1
            if a[s[i]] == 3:
                print(s[i])
                break
        else:
            a[s[i]] = 1