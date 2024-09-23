# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/743853af75fc4026939a682b86535f79

class BinDecimal:
    def printBin(self, num):
        # write code here
        y = num
        x = y - int(y)
        z = int(y)
        integer = int(bin(z)[2:])


        if x == 0:
            return str(integer)
        else:
            p = 0

            while ((2**p)*x)%1 != 0:
               p += 1

               num = int(x*(2**p))
               result = ''

            if num == 0:
                return str(float(integer))

            while num > 0:
                result = str(num % 2) + result
                num //= 2

            for i in xrange(p - len(result)):
                result = "0" + result

            result = str(integer) + "." + result[-p:]

            if len(result[2:]) > 32:
                return "Error"

            return result