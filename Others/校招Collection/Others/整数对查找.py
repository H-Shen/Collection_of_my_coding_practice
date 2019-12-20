# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/87d5a092a1d647479103e519a6c0a205

class FindPair:
    def countPairs(self, A, n, tsum):
        # write code here
        from collections import Counter
        if A == []:
            return 0
        a, b, cnt = Counter(A), list(set(A)), 0
        while len(b) != 0 :
            i = b[0]
            j = tsum - i
            if j in a and j != i:
                cnt += a[i] * a[j]
                del a[i], a[j]
                del b[b.index(i)]
                del b[b.index(j)]
            elif not j in a:
                del a[i]
                del b[b.index(i)]
            elif i == j:
                cnt += (a[i] * (a[i] - 1)) // 2
                del a[i]
                del b[b.index(i)]
        return cnt