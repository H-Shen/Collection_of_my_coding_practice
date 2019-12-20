# https://www.nowcoder.com/practice/5759c29a28cb4361bc3605979d5a6130

try:
    while 1:
        (lambda x : print(x) if x != "0.00" else None)("%.2f" %(eval(input())))
except:
    pass