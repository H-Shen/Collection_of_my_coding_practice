# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/fd84c5485c894be396220eff3846a317

table = {1:'One',2:'Two',3:'Three',4:'Four',
     5:'Five',6:'Six',7:'Seven',8:'Eight',
     9:'Nine',10:'Ten',11:'Eleven',12:'Twelve',
     13:'Thirteen',14:'Fourteen',15:'Fifteen',
     16:'Sixteen',17:'Seventeen',18:'Eighteen',
     19:'Nineteen',20:'Twenty',30:'Thirty',40:'Forty',
     50:'Fifty',60:'Sixty',70:'Seventy',80:'Eighty',
     90:'Ninety',100:'Hundred'}

def handle(n):
    global table
    if n <= 20:
        return table[n]
    if n <= 100 and n % 10 == 0:
        return table[n]
    if n < 100:
        return table[n // 10 * 10] + ' ' + table[n - n // 10 * 10]
    if n % 100 == 0:
        return table[n // 100] + ' Hundred'
    if n - n // 100 * 100 <= 20 or (n - n // 100 * 100) % 10 == 0:
        return table[n // 100] + ' Hundred ' + table[n - n // 100 * 100]
    return table[n // 100] + ' Hundred ' + table[(n - n // 100 * 100) // 10 * 10] + ' ' + table[n - n // 10 * 10]

class ToString:
    def toString(self, x):
        # write code here
        n = x
        if n == 0:
            return 'Zero'
        elif n == 1000000000000:
            return 'One Trillion'
        else:
            bits = [0, 0, 0, 0]
            bits[0] = n // (10 ** 9)
            bits[1] = n // (10 ** 6) - bits[0] * 10 ** 3
            bits[2] = n // (10 ** 3) - bits[0] * 10 ** 6 - bits[1] * 10 ** 3
            bits[3] = n - bits[0] *  10 ** 9 - bits[1] * 10 ** 6 - bits[2] * 10 ** 3
            result = ''
            if bits[0] != 0:
                result = handle(bits[0]) + ' Billion,' + result
            if bits[1] != 0:
                result = result + handle(bits[1]) + ' Million,'
            if bits[2] != 0:
                result = result + handle(bits[2]) + ' Thousand,'
            try:
                result += handle(bits[3])
                return result
            except:
                return result[:-1]