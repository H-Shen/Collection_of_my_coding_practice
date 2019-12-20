# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720

class Solution:
    # 返回对应char
    string={}
    s=''
    def FirstAppearingOnce(self):
        # write code here
        if self.string==None:
            return '#'
        for i in self.s:
            if self.string[i]==1:
                return i
        return '#'
    def Insert(self, char):
        # write code here
        self.s+=char;
        if char in self.string:
            self.string[char]=self.string[char]+1
        else:
            self.string[char]=1