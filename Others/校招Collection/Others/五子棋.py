# https://www.nowcoder.com/practice/a811535fed784ea492b63622c28c75c5

def arrayPrint(arr, flag=True):
    n = 20
    result = []
    a = [['a'] * (n * 2 - 1) for i in xrange(n * 2 - 1)]

    if flag == False:
        arr = [i[::-1] for i in arr]

    for i in xrange(n):
        for j in xrange(n):
            a[i][i + j] = arr[i][j]


    for i in xrange(3, n * 2 - 1 - 3):
        L = []
        for j in xrange(n * 2 - 1):
            current = a[j][i]
            if current != 'a':
                L.append(current)
        result.append(L)

    for i in xrange(33):
        current_len = len(result[i])
        for j in xrange(current_len - 1):
            if result[i][j: j + 5] == ['*', '*', '*', '*', '*'] or result[i][j: j + 5] == ['+', '+', '+', '+', '+']:
                return True

    return False


def check(grid):
    for i in xrange(20):
        for j in xrange(16):
            if grid[i][j: j + 5] == '*****' or grid[i][j: j + 5] == '+++++':
                return True

    mirrorGrid = list(zip(*grid))
    for i in xrange(20):
        for j in xrange(16):
            if mirrorGrid[i][j: j + 5] == ('*', '*', '*', '*', '*') or mirrorGrid[i][j: j + 5] == ('+', '+', '+', '+', '+'):
                return True

    if arrayPrint(grid, flag=True) or arrayPrint(grid, flag=False):
        return True
    return False


try:
    while 1:
        grid = []
        for grid_i in xrange(20):
           grid_t = raw_input()
           grid.append(grid_t)
        if check(grid):
            print 'Yes'
        else:
            print 'No'
except:
    pass