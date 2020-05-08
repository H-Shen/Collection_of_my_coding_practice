class Complex(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def __add__(self,other):
        A = self.a + other.a
        B = self.b + other.b

        result = complex(A,B)

        Rr = result.real
        Im = result.imag

        strRr = '%.2f' % Rr
        strIm = '%.2f' % Im

        if Im > 0:
            return strRr + '+' + strIm + 'i'
        elif Im == 0:
            return strRr + '+0.00i'
        else:
            return strRr + strIm + 'i'

    def __sub__(self,other):

        A = self.a - other.a
        B = self.b - other.b

        result = complex(A,B)

        Rr = result.real
        Im = result.imag

        strRr = '%.2f' % Rr
        strIm = '%.2f' % Im

        if Im > 0:
            return strRr + '+' + strIm + 'i'
        elif Im == 0:
            return strRr + '+0.00i'
        else:
            return strRr + strIm + 'i'

    def __mul__(self,other):

        A = complex(self.a, self.b)
        B = complex(other.a, other.b)

        result = A * B

        Rr = result.real
        Im = result.imag

        strRr = '%.2f' % Rr
        strIm = '%.2f' % Im

        if Im > 0:
            return strRr + '+' + strIm + 'i'
        elif Im == 0:
            return strRr + '+0.00i'
        else:
            return strRr + strIm + 'i'

    def __truediv__(self,other):

        A = complex(self.a, self.b)
        B = complex(other.a, other.b)

        result = A / B

        Rr = result.real
        Im = result.imag

        strRr = '%.2f' % Rr
        strIm = '%.2f' % Im

        if Im > 0:
            return strRr + '+' + strIm + 'i'
        elif Im == 0:
            return strRr + '+0.00i'
        else:
            return strRr + strIm + 'i'

    def Mod(self):

        result = ((self.a) ** 2 + (self.b) ** 2) ** (1 / 2)
        string = '%.2f' % result

        return string + '+0.00i'

In = list(map(float,input().split()))
In2 = list(map(float,input().split()))

print(Complex(In[0],In[1]) + Complex(In2[0],In2[1]))
print(Complex(In[0],In[1]) - Complex(In2[0],In2[1]))
print(Complex(In[0],In[1]) * Complex(In2[0],In2[1]))
print(Complex(In[0],In[1]) / Complex(In2[0],In2[1]))
print(Complex(In[0],In[1]).Mod())
print(Complex(In2[0],In2[1]).Mod())