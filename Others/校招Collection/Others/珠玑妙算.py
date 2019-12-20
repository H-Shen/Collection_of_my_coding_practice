# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/ed21d2b1183a401797fdf06e88cc5993

class Result:
    def calcResult(self, A, guess):
        # write code here
        from collections import Counter
        a, b = '', ''
        m, n = 0, 0
        L = len(A)
        for i in xrange(L):
            if A[i] == guess[i]:
                m += 1
            else:
                a += A[i]
                b += guess[i]
        common = set(a) & set(b)
        counter_a, counter_b = Counter(a), Counter(b)
        for j in common:
            if counter_b[j] < counter_a[j]:
                n += counter_b[j]
            else:
                n += counter_a[j]
        return [m, n]