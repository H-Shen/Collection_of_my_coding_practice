baseStr = {10:"a",11:"b",12:"c",13:"d",14:"e",15:"f",16:"g",17:"h",18:"i",19:"j",20:'k',21:'l',22:'m'
           ,23:'n',24:'o',25:'p',26:'q',27:'r',28:'s',29:'t',30:'u',31:'v',32:'w',33:'x',34:'y',35:'z'}

def decimalToAny(num,n):
   global  baseStr
   new_num_str = ""
   while num != 0:
       remainder = num % n
       if 36 > remainder > 9:
           remainder_string = baseStr[remainder]
       else:
           remainder_string = str(remainder)
       new_num_str = remainder_string+new_num_str
       num = num // n
   return new_num_str


try:
    while 1:
        N, M = map(int, raw_input().split())
        print decimalToAny(N, M).upper()
except:
    pass