# https://www.nowcoder.com/practice/7eb53c86e50845f6a2eafe7ea0fe9ef9

s = input()
try:
    pos = -1
    fileNameExtension = ''
    while s[pos] != '.':
        fileNameExtension = s[pos] + fileNameExtension
        pos -= 1
    print(fileNameExtension)
except:
    print('null')