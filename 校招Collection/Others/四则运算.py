# https://www.nowcoder.com/practice/9999764a61484d819056f807d2a91f1e

L = raw_input()
expr = ''
for i in L:
    if i == '{' or i == '[':
        expr += '('
    elif i == '}' or i == ']':
        expr += ')'
    else:
        expr += i
print eval(expr)
