# https://www.nowcoder.com/practice/9c550b6fe85d48bcad5a6025c6dc447d

try:
    while 1:
        m, n = map(int, raw_input().split())
        matrix = [map(int, raw_input().split()) for i in xrange(m)]
        for j in xrange(m):
            MaxIndex = matrix[j].index(max(matrix[j]))
            Sum = sum(matrix[j])
            matrix[j][MaxIndex] = Sum
            print ' '.join(map(str, matrix[j]))
except:
    pass