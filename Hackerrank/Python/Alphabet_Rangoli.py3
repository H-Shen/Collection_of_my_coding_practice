import string

def print_rangoli(size):
    table = string.ascii_lowercase[:size]
    M = size * 4 - 3
    N = size - 1
    x = (M + 1) // 2
    contentList = list()

    for i in range(1, N + 1):
        k = '-'.join(table[::-1][:i])
        contentList.append(k.rjust(x,'-') + k.rjust(x,'-')[::-1][1:])
        print(k.rjust(x,'-') + k.rjust(x,'-')[::-1][1:])

    #MIDDLE
    print('-'.join(table[::-1] + table[1:]))

    contentList.reverse()
    for j in range(len(contentList)):
        print(contentList[j])

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)