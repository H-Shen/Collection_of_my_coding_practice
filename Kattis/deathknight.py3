# https://open.kattis.com/problems/deathknight
cnt = 0
for i in range(int(input())):
    s = input()
    if not 'CD' in s:
        cnt += 1
print(cnt)
    
