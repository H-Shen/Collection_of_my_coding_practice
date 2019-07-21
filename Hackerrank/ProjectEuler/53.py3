def C(n, m, K):
    result = 0
    s, j, k = 1, n, 1
    for i in range(1, m + 1):
        s *= j
        k *= i
        j -= 1
        if (s // k) > K:
            result += 1
    return result

N, K = map(int, input().split())
print(sum(C(i, i, K) for i in range(2, N + 1)))
