baseStr = {10:"A",11:"B",12:"C",13:"D",14:"E",15:"F",16:"G",17:"H",18:"I",19:"J"}
strBase = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15, 'G': 16, 'H': 17,
           'I': 18, 'J': 19, '0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5,
           '6': 6, '7': 7, '8': 8, '9': 9}

def decimalToAny(num,n):
   global  baseStr
   new_num_str = ""
   while num != 0:
       remainder = num % n
       if 20 > remainder > 9:
           remainder_string = baseStr[remainder]
       elif remainder >=20:
           remainder_string = "("+str(remainder)+")"
       else:
           remainder_string = str(remainder)
       new_num_str = remainder_string+new_num_str
       num = num // n
   return new_num_str


try:
    while 1:
        a, b = map(int, raw_input().split())
        c = decimalToAny(a, b)
        if b > 10:
            d = sum(map(lambda x:strBase[x], c))
        else:
            d = sum(map(int, c))
        print decimalToAny(d, b)
except:
    pass