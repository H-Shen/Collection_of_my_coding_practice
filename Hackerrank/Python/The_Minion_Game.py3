def minion_game(s):

    L = len(s)
    vowelTable = {'A','E','I','O','U'}
    K, S = 0, 0
    for i in range(L):
        if s[i] in vowelTable:
            K += (L-i)
        else:
            S += (L-i)

    if K > S:
        print("Kevin", K)
    elif K < S:
        print("Stuart", S)
    else:
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)