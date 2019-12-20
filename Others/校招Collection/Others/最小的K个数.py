# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf

import heapq
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        if tinput == [] or k > len(tinput):
            return []
        return heapq.nsmallest(k, tinput)