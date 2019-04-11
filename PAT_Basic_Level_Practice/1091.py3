MAXN = 10

def test(k):
    haveAns = False
    for n in range(1, MAXN):
        str_a = str(k)[::-1]
        str_b = str(k * k * n)[::-1]
        if str_b.find(str_a) == 0:
            print(str(n) + " " + str(k * k * n))
            haveAns = True
            break
    if not haveAns:
        print("No")

_ = input()
A = list(map(int, input().split()))
for i in A:
    test(i)