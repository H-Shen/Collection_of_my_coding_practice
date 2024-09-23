# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7

from itertools import permutations
class Solution:
    def Permutation(self, ss):
        # write code here
        if ss == '':
            return []
        return sorted(set(map(lambda x:''.join(x), permutations(ss))))