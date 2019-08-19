def decimalToAny(num,n):
   baseStr = {10:"a",11:"b",12:"c",13:"d",14:"e",15:"f",16:"g",17:"h",18:"i",19:"j"}
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
        num, n = map(int, raw_input().split())
        print decimalToAny(num, n).count('1')
except:
    pass