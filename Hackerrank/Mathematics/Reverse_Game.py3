for _ in range(int(input())):
    s, k = list(map(int,input().split()))
    if s % 2 == 0:
        L1 = list(range(s - 1, s // 2 - 1, -1))
        L2 = list(range(0, s // 2, 1))
        result = [item for sublist in zip(L1, L2) for item in sublist]
    else:
        L1 = list(range(s - 1, (s - 1) // 2 - 1, -1))
        L2 = list(range(0, (s - 1) // 2, 1))
        result = [item for sublist in zip(L1, L2) for item in sublist] + [(s - 1) // 2]

    print(result.index(k))
