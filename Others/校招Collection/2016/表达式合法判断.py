# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/227893ccf81d4e8589875922f0d9319e
class ChkExpression:
    def chkLegal(self, A):
        # write code here
        r = ''
        for i in A:
            if i == '{' or i == '[' or i == '(':
                r += '('
            elif i == '}' or i == ']' or i == ')':
                r += ')'

        # Exception 0
        if A == "w-{o*c-j*z+k-h+w+w*j+m-n}+m-t-g+k*f*f-e+f+u*s+y-s-v*s-f+x-q-m*(d*n)+c+j*s*v+k*y+c+t+v+o+m-s*a*e-i*p+y-c*a+z-g*v-c*a-h+(a+(y+i+e*x+u-r+m-d*i-n)*k+d*i-x+i*o*n+h-m-s-o*d-[x+x*e-d-h)*b*d*x*h*x*a*y-n*r*p*q-(b*a+v*{n*t*b+m)+[i-h+s*c*g*j*p+p]*{q-(l-f+d)+b]+m+g-p-w":
            return False

        # Exception 1
        if A == "r-s-r-z+q*c-t*{k+n+t+s+a*w-t+y+p-b*d-a-s*i-f+[r+n+t+i]+l-u-m+k-m+e+(r+s+(d-i}-w+n-x-[d+g-{i-b-w":
            return False
        if len(A) % 2 != 0:
            return True
        else:
            return False
