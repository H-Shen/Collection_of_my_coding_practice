for i in range(int(input())):
    s = input()
    if len(s) >= 10:
        if s[:10] == 'hackerrank' and s[-10:] == 'hackerrank':
            print(0)
        elif s[:10] == 'hackerrank':
            print(1)
        elif s[-10:] == 'hackerrank':
            print(2)
        else:
            print(-1)
    else:
        print(-1)
