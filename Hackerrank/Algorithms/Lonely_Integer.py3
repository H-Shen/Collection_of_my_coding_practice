#!/usr/bin/py
# Head ends here
def lonelyinteger(b):
    L0 = list(b)
    L = list(set(L0))
    for i in L:
        if L0.count(i) == 1:
            answer = i
            break
    return answer
# Tail starts here
if __name__ == '__main__':
    a = int(input())
    b = map(int, input().strip().split(" "))
    print(lonelyinteger(b))
