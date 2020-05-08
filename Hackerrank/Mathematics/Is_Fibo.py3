for i in range(int(input())):
    n = int(input())
    a = (n ** 2) * 5 + 4
    b = (n ** 2) * 5 - 4
    if (a ** 0.5 % 1) == 0 or (b ** 0.5 % 1) == 0:
        print('IsFibo')
    else:
        print('IsNotFibo')
