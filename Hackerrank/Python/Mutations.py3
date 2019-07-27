def mutate_string(a, b, c):
    return a[:b] + c + a[(b + 1):]

if __name__ == '__main__':
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)