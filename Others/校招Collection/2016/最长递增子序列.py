# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/585d46a1447b4064b749f08c2ab9ce66
class AscentSequence:
    def findLongest(self, A, n):
        # write code here
        P = {0:[]}
        for i in A:
            temp = sorted(P)
            for p in temp:
                a = P[p]
                if a and i > a[-1]:
                        break
            P[p-1] = a + [i]
        return len(P[min(P)])