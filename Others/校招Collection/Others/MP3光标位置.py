# https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15

try:
    while 1:

        n = input()
        s = raw_input()

        if n <= 4:
            currentList = [i for i in xrange(1, n + 1)]
            currentPos = 1
            for j in s:
                if j == 'U' and currentPos == 1:
                    currentPos = n
                elif j == 'D' and currentPos == n:
                    currentPos = 1
                elif j == 'U':
                    currentPos -= 1
                else:
                    currentPos += 1
        else:
            currentList = [1, 2, 3, 4]
            currentPos = 1
            for j in s:
                if j == 'U' and currentPos == 1:
                    currentPos = n
                    currentList = [n - 3, n - 2, n - 1, n]
                elif j == 'D' and currentPos == n:
                    currentPos = 1
                    currentList = [1, 2, 3, 4]
                elif j == 'U' and currentPos == currentList[0]:
                    currentPos -= 1
                    currentList = [i - 1 for i in currentList]
                elif j == 'D' and currentPos == currentList[-1]:
                    currentPos += 1
                    currentList = [i + 1 for i in currentList]
                elif j == 'U':
                    currentPos -= 1
                else:
                    currentPos += 1

        print ' '.join(map(str, currentList))
        print currentPos

except:
    pass