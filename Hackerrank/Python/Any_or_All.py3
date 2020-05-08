N,S = int(input()),list(input().strip().split())
print(any([S[i] == S[i][::-1] for i in range(N)]) and all([int(S[j]) > 0 for j in range(N)]))
