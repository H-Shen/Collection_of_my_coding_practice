T = int(input())

for i in range(T):
    S = input()
    S = list(S)
    R = S[:]
    R.reverse()
    Flag = 0

    for i in range(1, len(S)):
        if abs(ord(S[i]) - ord(S[i - 1])) != abs(ord(R[i]) - ord(R[i - 1])):
            print('Not Funny')
            Flag = 1
            break
    if Flag == 0:
        print('Funny')
