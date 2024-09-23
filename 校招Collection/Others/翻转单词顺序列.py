# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3

class Solution:
    def ReverseSentence(self, s):
        # write code here
        return ' '.join(s.split()[::-1]) if s.strip() != '' else s #如果s只有空格组成，那就直接返回，不然再join
